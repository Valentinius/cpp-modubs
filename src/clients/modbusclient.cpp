#include "modbusclient.h"

#include <utility>


ModbusClient::ModbusClient(std::string ip, uint16_t port, ModbusFramer framer):
    ip(std::move(ip)), port(port), framer(framer){

}

std::shared_ptr<ModbusRequest> ModbusClient::writeCoil(uint16_t register_num,
                                      uint16_t value,
                                      uint8_t slave_id,
                                      std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::writeCoils(uint16_t register_num,
                                       uint16_t *values,
                                       uint16_t count,
                                       uint8_t slave_id,
                                       std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::writeCoils(uint16_t register_num,
                                       const std::vector<uint16_t> &values,
                                       uint8_t slave_id,
                                       std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::writeHoldingRegister(uint16_t register_num,
                                                 uint16_t value,
                                                 uint8_t slave_id,
                                                 std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::writeHoldingRegisters(uint16_t register_num,
                                                  uint16_t *values,
                                                  uint16_t count,
                                                  uint8_t slave_id,
                                                  std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::writeHoldingRegisters(uint16_t register_num,
                                                  const std::vector<uint16_t> &values,
                                                  uint8_t slave_id,
                                                  std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::sendRawRequest(uint8_t *request,
                                           size_t request_size,
                                           uint8_t slave_id,
                                           uint8_t *response,
                                           size_t &response_size) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::sendRequest(ModbusFunction function,
                                        uint8_t *buffer,
                                        size_t buffer_size,
                                        uint8_t slave_id) {
  return nullptr;
}

uint8_t  *ModbusClient::formPDU(ModbusFunction function,
                           const uint8_t *buffer,
                           size_t buffer_size) {

  uint8_t *result = new uint8_t[1 + buffer_size];
  result[0] = (uint8_t)function;

  for (size_t i = 0; i < buffer_size; i++) result[i + 1] = buffer[i];
  return result;
}

uint8_t *ModbusClient::formRequest(ModbusFunction function,
                                   const uint8_t *buffer,
                                   size_t buffer_size,
                                   uint8_t slave_id) {
  switch (this->framer) {
    case ModbusFramer::RTU:
      return ModbusClient::formRTURequest(function, buffer, buffer_size, slave_id);
    case ModbusFramer::ASCII:
      return ModbusClient::formASCIIRequest(function, buffer, buffer_size, slave_id);
    case ModbusFramer::TCP:
      return ModbusClient::formTCPRequest(function, buffer, buffer_size, slave_id);
  }
  return nullptr;
}

uint8_t *ModbusClient::formTCPRequest(ModbusFunction function,
                                      const uint8_t *buffer,
                                      size_t buffer_size,
                                      uint8_t slave_id) {
  return nullptr;
}

uint8_t *ModbusClient::formRTURequest(ModbusFunction function,
                                      const uint8_t *buffer,
                                      size_t buffer_size,
                                      uint8_t slave_id) {
  uint8_t *request = new uint8_t[buffer_size + 2];
  return nullptr;
}

uint8_t *ModbusClient::formASCIIRequest(ModbusFunction function,
                                        const uint8_t *buffer,
                                        size_t buffer_size,
                                        uint8_t slave_id) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readDiscreteInput(uint16_t register_num,
                                              uint8_t slave_id,
                                              uint8_t &value,
                                              std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readDiscreteInputs(uint16_t register_num,
                                               uint16_t count,
                                               uint8_t slave_id,
                                               std::vector<uint8_t> &values,
                                               std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readCoil(uint16_t register_num,
                                     uint8_t slave_id,
                                     uint8_t &value,
                                     std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readCoils(uint16_t register_num,
                                      uint16_t count,
                                      uint8_t slave_id,
                                      std::vector<uint8_t> &values,
                                      std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readInputRegister(uint16_t register_num,
                                              uint8_t slave_id,
                                              uint8_t &value,
                                              std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readInputRegisters(uint16_t register_num,
                                               uint16_t count,
                                               uint8_t slave_id,
                                               std::vector<uint8_t> &values,
                                               std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readHoldingRegister(uint16_t register_num,
                                                uint8_t slave_id,
                                                uint8_t &value,
                                                std::vector<uint8_t> &result) {
  return nullptr;
}

std::shared_ptr<ModbusRequest> ModbusClient::readHoldingRegisters(uint16_t register_num,
                                                 uint16_t count,
                                                 uint8_t slave_id,
                                                 std::vector<uint8_t> &values,
                                                 std::vector<uint8_t> &result) {
  return nullptr;
}
