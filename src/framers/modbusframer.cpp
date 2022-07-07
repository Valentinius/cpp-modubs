#include "modbusframer.h"

using modbus::enums::ModbusFunction;
using modbus::utils::toMsbLsb;


void ModbusFramer::parseRequest(const std::shared_ptr<ModbusRequest> &request,
                                uint8_t *raw_request,
                                size_t &raw_request_size) {
  *raw_request++ = request->getSlaveId();
  switch (request-> getRequestType()) {
    case modbus::enums::SINGLE_REGISTER_WRITE:break;
    case modbus::enums::MULTIPLE_REGISTERS_WRITE:break;
    case modbus::enums::PARTIAL_REGISTER_WRITE:break;
    case modbus::enums::SINGLE_REGISTER_READ:break;
    case modbus::enums::MULTIPLE_REGISTERS_READ:break;
    case modbus::enums::PARTIAL_REGISTER_READ:break;
  }
}

void ModbusFramer::parseResponse(std::shared_ptr<ModbusRequest> &request,
                                 uint8_t *raw_request,
                                 size_t raw_request_size) {

}

ModbusError ModbusFramer::parseError(uint8_t *raw_request, size_t raw_request_size) {
  return ModbusError::NO_ERROR;
}

bool ModbusFramer::parseSingleRegisterWriteRequest(const std::shared_ptr<ModbusRequest> &request,
                                                   uint8_t *raw_request) {
  std::vector<uint16_t> values;
  switch (request->getRegisterType()) {
    case modbus::enums::COILS:
      *raw_request++ = (uint8_t) ModbusFunction::WRITE_COILS_ONE;
      if (!request->getValues(values)) return false;

      if (!values.empty()) toMsbLsb(0xFF00, *(raw_request + 2), *(raw_request + 3));
      else toMsbLsb(0x0000, *(raw_request + 2), *(raw_request + 3));
      break;
    case modbus::enums::HOLDING_REGISTERS:
      *raw_request++ = (uint8_t) ModbusFunction::WRITE_HOLDING_REGISTERS_ONE;
      if (!request->getValues(values)) return false;

      if (!values.empty()) toMsbLsb(values[0], *(raw_request + 2), *(raw_request + 3));
      break;
    default:
      return false;
  }

  toMsbLsb(request->getRegisters()[0], *(raw_request), *(raw_request + 1));
  raw_request += 4;
  return true;
}

bool ModbusFramer::parseMultipleRegistersWriteRequest(const std::shared_ptr<ModbusRequest> &request,
                                                      uint8_t *raw_request) {
  std::vector<uint16_t> values;
  switch (request->getRegisterType()) {
    case modbus::enums::COILS:
      *raw_request++ = (uint8_t) ModbusFunction::WRITE_COILS_GROUP;
      if (!request->getValues(values)) return false;
      if (values.empty()) return false;

      for (size_t i = 0; i < values.size(); i++) {
        if (values[i]) toMsbLsb(0xFF00, *(raw_request + i + 4), *(raw_request + i + 5));
        else toMsbLsb(0x0000, *(raw_request + i + 4), *(raw_request + i + 5));
      }
      break;
    case modbus::enums::HOLDING_REGISTERS:
      *raw_request++ = (uint8_t) ModbusFunction::WRITE_HOLDING_REGISTERS_GROUP;
      if (!request->getValues(values)) return false;
      if (values.empty()) return false;

      for (size_t i = 0; i < values.size(); i++)
        toMsbLsb(values[i], *(raw_request + i + 4), *(raw_request + i + 5));
      break;
    default:
      return false;
  }

  const std::vector<uint16_t> registers = request->getRegisters();
  if (registers[1] - registers[0] == 1) {
    toMsbLsb(registers[0], *raw_request, *(raw_request + 1));
    toMsbLsb(registers.size(), *(raw_request + 2), *(raw_request + 3));
  } else return false;

  raw_request += 4 + values.size() * 2;
  return true;
}

bool ModbusFramer::parsePartialRegisterWriteRequest(const std::shared_ptr<ModbusRequest> &request,
                                                    uint8_t *raw_request) {
  return false;
}

bool ModbusFramer::parseSingleRegisterReadRequest(const std::shared_ptr<ModbusRequest> &request,
                                                  uint8_t *raw_request) {
  if (!this->parseReadRequest(request, raw_request)) return false;
  toMsbLsb(request->getRegisters().size(), *raw_request, *(raw_request + 1));
  return false;
}

bool ModbusFramer::parseMultipleRegistersReadRequest(const std::shared_ptr<ModbusRequest> &request,
                                                     uint8_t *raw_request) {
  if (!this->parseReadRequest(request, raw_request)) return false;
  const std::vector<uint16_t> registers = request->getRegisters();
   // TODO: дописать!!
}

bool ModbusFramer::parsePartialRegisterReadRequest(const std::shared_ptr<ModbusRequest> &request,
                                                   uint8_t *raw_request) {
  std::vector<uint16_t> values;
  switch (request->getRegisterType()) {
    case modbus::enums::COILS:break;
    case modbus::enums::DISCRETE_INPUTS:break;
    case modbus::enums::HOLDING_REGISTERS:break;
    case modbus::enums::INPUT_REGISTERS:break;
  }
  return false;
}

bool ModbusFramer::parseReadRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request) {
  std::vector<uint16_t> values;
  switch (request->getRegisterType()) {
    case modbus::enums::COILS:
      *raw_request++ = (uint8_t) ModbusFunction::READ_COILS_GROUP;
      break;
    case modbus::enums::DISCRETE_INPUTS:
      *raw_request++ = (uint8_t) ModbusFunction::READ_DISCRETE_INPUTS_GROUP;
      break;
    case modbus::enums::HOLDING_REGISTERS:
      *raw_request++ = (uint8_t) ModbusFunction::READ_HOLDING_REGISTERS_GROUP;
      break;
    case modbus::enums::INPUT_REGISTERS:
      *raw_request++ = (uint8_t) ModbusFunction::READ_INPUTS_GROUP;
      break;
  }

  if (!request->getValues(values)) return false;
  if (values.empty()) return false;

  toMsbLsb(request->getRegisters()[0], *raw_request, *(raw_request + 1));
  raw_request += 3;
  return true;
}
