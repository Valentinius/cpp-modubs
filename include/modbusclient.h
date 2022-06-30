#ifndef UNTITLED1_INCLUDE_MODBUSCLIENT_H_
#define UNTITLED1_INCLUDE_MODBUSCLIENT_H_

#include <string>
#include <vector>

#include "utils.h"

using modbus::enums::RequestStatus;
using modbus::enums::ModbusFramer;
using modbus::enums::RegisterType;
using modbus::enums::ModbusFunction;


class ModbusClient {

 public:
  ModbusClient(std::string ip, uint16_t port, ModbusFramer framer = ModbusFramer::RTU);

  virtual bool connect() = 0;
  virtual bool connect(std::string ip, uint16_t port) = 0;
  virtual bool disconnect() = 0;

  RequestStatus readDiscreteInput(uint16_t register_num,
                                  uint8_t slave_id,
                                  uint8_t &value,
                                  std::vector<uint8_t> &result);

  RequestStatus readDiscreteInputs(uint16_t register_num,
                                   uint16_t count,
                                   uint8_t slave_id,
                                   std::vector<uint8_t> &values,
                                   std::vector<uint8_t> &result);

  RequestStatus readCoil(uint16_t register_num,
                         uint8_t slave_id,
                         uint8_t &value,
                         std::vector<uint8_t> &result);

  RequestStatus readCoils(uint16_t register_num,
                          uint16_t count,
                          uint8_t slave_id,
                          std::vector<uint8_t> &values,
                          std::vector<uint8_t> &result);

  RequestStatus writeCoil(uint16_t register_num,
                          uint16_t value,
                          uint8_t slave_id,
                          std::vector<uint8_t> &result);

  RequestStatus writeCoils(uint16_t register_num,
                           uint16_t *values,
                           uint16_t count,
                           uint8_t slave_id,
                           std::vector<uint8_t> &result);

  RequestStatus writeCoils(uint16_t register_num,
                           const std::vector<uint16_t> &values,
                           uint8_t slave_id,
                           std::vector<uint8_t> &result);

  RequestStatus readInputRegister(uint16_t register_num,
                                  uint8_t slave_id,
                                  uint8_t &value,
                                  std::vector<uint8_t> &result);

  RequestStatus readInputRegisters(uint16_t register_num,
                                   uint16_t count,
                                   uint8_t slave_id,
                                   std::vector<uint8_t> &values,
                                   std::vector<uint8_t> &result);

  RequestStatus readHoldingRegister(uint16_t register_num,
                                    uint8_t slave_id,
                                    uint8_t &value,
                                    std::vector<uint8_t> &result);

  RequestStatus readHoldingRegisters(uint16_t register_num,
                                     uint16_t count,
                                     uint8_t slave_id,
                                     std::vector<uint8_t> &values,
                                     std::vector<uint8_t> &result);

  RequestStatus writeHoldingRegister(uint16_t register_num,
                                     uint16_t value,
                                     uint8_t slave_id,
                                     std::vector<uint8_t> &result);

  RequestStatus writeHoldingRegisters(uint16_t register_num,
                                      uint16_t *values,
                                      uint16_t count,
                                      uint8_t slave_id,
                                      std::vector<uint8_t> &result);

  RequestStatus writeHoldingRegisters(uint16_t register_num,
                                      const std::vector<uint16_t> &values,
                                      uint8_t slave_id,
                                      std::vector<uint8_t> &result);

  RequestStatus sendRawRequest(uint8_t *request,
                               size_t request_size,
                               uint8_t slave_id,
                               uint8_t *response,
                               size_t &response_size);

  RequestStatus sendRequest(ModbusFunction function,
                            uint8_t *buffer,
                            size_t buffer_size,
                            uint8_t slave_id);

 protected:
  static uint8_t *formPDU(ModbusFunction function,
                          const uint8_t *buffer,
                          size_t buffer_size);
  uint8_t *formRequest(ModbusFunction function,
                       const uint8_t *buffer,
                       size_t buffer_size,
                       uint8_t slave_id);

  static uint8_t *formTCPRequest(ModbusFunction function,
                                 const uint8_t *buffer,
                                 size_t buffer_size,
                                 uint8_t slave_id);

  static uint8_t *formRTURequest(ModbusFunction function,
                                 const uint8_t *buffer,
                                 size_t buffer_size,
                                 uint8_t slave_id);

  static uint8_t *formASCIIRequest(ModbusFunction function,
                                   const uint8_t *buffer,
                                   size_t buffer_size,
                                   uint8_t slave_id);

  ModbusFramer framer;
  bool connection_status;
  std::string ip;
  uint16_t port;


};
#endif //UNTITLED1_INCLUDE_MODBUSCLIENT_H_
