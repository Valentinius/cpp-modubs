#include "modbussession.h"
#include "modbustcpclient.h"

#include <future>

using modbus::utils::toMsbLsb;
using modbus::utils::fromMsbLsb;


ModbusSession::ModbusSession() {

}

void ModbusSession::addClient(std::shared_ptr<ModbusClient> modbus_client) {
  this->clients.push_back(modbus_client);
  this->request_queues.emplace_back();
}

void ModbusSession::addClient(std::string ip, uint16_t port, ModbusFramer modbus_framer) {
  this->clients.push_back(std::make_shared<ModbusTCPClient>(ip, port, modbus_framer));
  this->request_queues.emplace_back();
}

void ModbusSession::removeClient(std::shared_ptr<ModbusClient> modbus_client) {
  for (int i = 0; i < this->clients.size(); i++) {
    if (this->clients[i] == modbus_client) {
      this->clients.erase(this->clients.begin() + i);
      this->request_queues.erase(this->request_queues.begin() + i);
      break;
    }
  }
}

void ModbusSession::removeClient(int client_num) {
  if (client_num >= 0 && client_num < this->clients.size()) {
    this->clients.erase(this->clients.begin() + client_num);
    this->request_queues.erase(this->request_queues.begin() + client_num);
  }
}

std::vector<bool> ModbusSession::run() {
  std::vector<bool> result;
  for (size_t i = 0; i < this->clients.size(); i++) {
    if (!this->clients[i]->connect()) result.push_back(i);
  }

  future_run_async = std::make_shared<std::future<void>>(std::async(&ModbusSession::_run, this));
  return result;
}

void ModbusSession::_run() {
  while (true) {
    for (size_t i = 0; i < this->clients.size(); i++) {
      std::shared_ptr<ModbusRequest> request = this->request_queues[i].top();
      this->request_queues[i].pop();

      std::vector<uint8_t> request_result;
      const std::vector<uint16_t> &registers = request->getRegisters();
      switch (request->getRequestType()) {
        case RequestType::MULTIPLE_REGISTERS_READ:
          this->_multipleRegistersReadProcess(request, registers, i, request_result);
          break;
        case RequestType::SINGLE_REGISTER_READ:
          this->_singleRegisterReadProcess(request, registers, i, request_result);
          break;
        case RequestType::PARTIAL_REGISTER_READ:
          this->_partialRegistersReadProcess(request, registers, i, request_result);
          break;
        case RequestType::MULTIPLE_REGISTERS_WRITE:
          this->_multipleRegistersWriteProcess(request, registers, i, request_result);
          break;
        case RequestType::SINGLE_REGISTER_WRITE:
          this->_singleRegisterWriteProcess(request, registers, i, request_result);
          break;
        case RequestType::PARTIAL_REGISTER_WRITE:
          this->_partialRegistersWriteProcess(request, registers, i, request_result);
          break;
      }
    }
  }
}

void ModbusSession::stop() {
  for (std::shared_ptr<ModbusClient> client: this->clients)
    client->disconnect();
}

void ModbusSession::terminate() {
  for (std::shared_ptr<ModbusClient> client: this->clients)
    client->disconnect();
}

std::shared_ptr<ModbusRequest> ModbusSession::addRequest(std::shared_ptr<ModbusRequest> request, size_t client_num) {
  request->setFutureAsync(this->future_run_async);

  if (client_num >= 0 && client_num < this->clients.size() && request) {
    this->request_queues[client_num].push(request);
  }

  return request;
}

void ModbusSession::_multipleRegistersReadProcess(const std::shared_ptr<ModbusRequest>& request,
                                                  const std::vector<uint16_t> &registers,
                                                  size_t client_id,
                                                  std::vector<uint8_t> &request_result) {
  std::vector<uint8_t> values;
  switch (request->getRegisterType()) {
    case RegisterType::COILS:
      if (registers[1] - registers[0] == 1)
        this->clients[client_id]->readCoils(registers[0], 2, request->getSlaveId(),
                                            values, request_result);
      break;
    case RegisterType::DISCRETE_INPUTS:
      if (registers[1] - registers[0] == 1)
        this->clients[client_id]->readDiscreteInputs(registers[0], 2, request->getSlaveId(),
                                                     values, request_result);
      break;
    case RegisterType::INPUT_REGISTERS:
      if (registers[1] - registers[0] == 1)
        this->clients[client_id]->readInputRegisters(registers[0], 2, request->getSlaveId(),
                                                     values, request_result);
      break;
    case RegisterType::HOLDING_REGISTERS:
      if (registers[1] - registers[0] == 1)
        this->clients[client_id]->readHoldingRegisters(registers[0], 2, request->getSlaveId(),
                                                       values, request_result);
      break;
    default:
      request->setRequestStatus(RequestStatus::INCORRECT_REQUEST);
      return;
  }

  uint32_t value;
  fromMsbLsb(values[0], values[1], value);
  request->setValue(value);
}

void ModbusSession::_singleRegisterReadProcess(const std::shared_ptr<ModbusRequest>& request,
                                               const std::vector<uint16_t> &registers,
                                               size_t client_id,
                                               std::vector<uint8_t> &request_result) {
  switch (request->getRegisterType()) {
    case RegisterType::COILS:
      break;
    case RegisterType::DISCRETE_INPUTS:
      break;
    case RegisterType::INPUT_REGISTERS:
      break;
    case RegisterType::HOLDING_REGISTERS:
      break;
  }
}

void ModbusSession::_partialRegistersReadProcess(const std::shared_ptr<ModbusRequest>& request,
                                                 const std::vector<uint16_t> &registers,
                                                 size_t client_id,
                                                 std::vector<uint8_t> &request_result) {
  switch (request->getRegisterType()) {
    case RegisterType::COILS:
      break;
    case RegisterType::DISCRETE_INPUTS:
      break;
    case RegisterType::INPUT_REGISTERS:
      break;
    case RegisterType::HOLDING_REGISTERS:
      break;
  }
}

void ModbusSession::_multipleRegistersWriteProcess(const std::shared_ptr<ModbusRequest>& request,
                                                   const std::vector<uint16_t> &registers,
                                                   size_t client_id,
                                                   std::vector<uint8_t> &request_result) {
  switch (request->getRegisterType()) {
    case RegisterType::COILS:
      break;
    case RegisterType::DISCRETE_INPUTS:
      break;
    case RegisterType::INPUT_REGISTERS:
      break;
    case RegisterType::HOLDING_REGISTERS:
      break;
  }
}

void ModbusSession::_singleRegisterWriteProcess(const std::shared_ptr<ModbusRequest>& request,
                                                const std::vector<uint16_t> &registers,
                                                size_t client_id,
                                                std::vector<uint8_t> &request_result) {
  switch (request->getRegisterType()) {
    case RegisterType::COILS:
      break;
    case RegisterType::DISCRETE_INPUTS:
      break;
    case RegisterType::INPUT_REGISTERS:
      break;
    case RegisterType::HOLDING_REGISTERS:
      break;
  }
}

void ModbusSession::_partialRegistersWriteProcess(const std::shared_ptr<ModbusRequest>& request,
                                                  const std::vector<uint16_t> &registers,
                                                  size_t client_id,
                                                  std::vector<uint8_t> &request_result) {
  switch (request->getRegisterType()) {
    case RegisterType::COILS:
      break;
    case RegisterType::DISCRETE_INPUTS:
      break;
    case RegisterType::INPUT_REGISTERS:
      break;
    case RegisterType::HOLDING_REGISTERS:
      break;
  }
}
