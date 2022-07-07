#ifndef UNTITLED1_INCLUDE_MODBUSCLIENT_H_
#define UNTITLED1_INCLUDE_MODBUSCLIENT_H_

#include <string>
#include <vector>
#include <memory>

#include "utils.h"

#include "modbusrequest.h"

using modbus::enums::ModbusFramer;
using modbus::enums::ModbusFunction;


class ModbusClient {

 public:
  ModbusClient(std::string ip, uint16_t port, ModbusFramer framer = ModbusFramer::RTU);

  virtual bool connect() = 0;
  virtual bool connect(std::string ip, uint16_t port) = 0;
  virtual bool disconnect() = 0;

  virtual std::shared_ptr<ModbusRequest> readDiscreteInput(uint16_t register_num,
                                  uint8_t slave_id,
                                  uint8_t &value,
                                  std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readDiscreteInputs(uint16_t register_num,
                                   uint16_t count,
                                   uint8_t slave_id,
                                   std::vector<uint8_t> &values,
                                   std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readCoil(uint16_t register_num,
                         uint8_t slave_id,
                         uint8_t &value,
                         std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readCoils(uint16_t register_num,
                          uint16_t count,
                          uint8_t slave_id,
                          std::vector<uint8_t> &values,
                          std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> writeCoil(uint16_t register_num,
                          uint16_t value,
                          uint8_t slave_id,
                          std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> writeCoils(uint16_t register_num,
                           uint16_t *values,
                           uint16_t count,
                           uint8_t slave_id,
                           std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> writeCoils(uint16_t register_num,
                           const std::vector<uint16_t> &values,
                           uint8_t slave_id,
                           std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readInputRegister(uint16_t register_num,
                                  uint8_t slave_id,
                                  uint8_t &value,
                                  std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readInputRegisters(uint16_t register_num,
                                   uint16_t count,
                                   uint8_t slave_id,
                                   std::vector<uint8_t> &values,
                                   std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readHoldingRegister(uint16_t register_num,
                                    uint8_t slave_id,
                                    uint8_t &value,
                                    std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> readHoldingRegisters(uint16_t register_num,
                                     uint16_t count,
                                     uint8_t slave_id,
                                     std::vector<uint8_t> &values,
                                     std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> writeHoldingRegister(uint16_t register_num,
                                     uint16_t value,
                                     uint8_t slave_id,
                                     std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> writeHoldingRegisters(uint16_t register_num,
                                      uint16_t *values,
                                      uint16_t count,
                                      uint8_t slave_id,
                                      std::vector<uint8_t> &result);

  virtual std::shared_ptr<ModbusRequest> writeHoldingRegisters(uint16_t register_num,
                                      const std::vector<uint16_t> &values,
                                      uint8_t slave_id,
                                      std::vector<uint8_t> &result);

  virtual void readDiscreteInput(std::shared_ptr<ModbusRequest> &request);

  virtual void readDiscreteInputs(std::shared_ptr<ModbusRequest> &request);

  virtual void readCoil(std::shared_ptr<ModbusRequest> &request);

  virtual void readCoils(std::shared_ptr<ModbusRequest> &request);

  virtual void writeCoil(std::shared_ptr<ModbusRequest> &request);

  virtual void writeCoils(std::shared_ptr<ModbusRequest> &request);

  virtual void readInputRegister(std::shared_ptr<ModbusRequest> &request);

  virtual void readInputRegisters(std::shared_ptr<ModbusRequest> &request);

  virtual void readHoldingRegister(std::shared_ptr<ModbusRequest> &request);

  virtual void readHoldingRegisters(std::shared_ptr<ModbusRequest> &request);

  virtual void writeHoldingRegister(std::shared_ptr<ModbusRequest> &request);

  virtual void writeHoldingRegisters(std::shared_ptr<ModbusRequest> &request);


  virtual std::shared_ptr<ModbusRequest> sendRawRequest(uint8_t *request,
                               size_t request_size,
                               uint8_t slave_id,
                               uint8_t *response,
                               size_t &response_size);

  virtual std::shared_ptr<ModbusRequest> sendRequest(ModbusFunction function,
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

  const ModbusFramer framer;
  bool connection_status;
  std::string ip;
  uint16_t port;


};
#endif //UNTITLED1_INCLUDE_MODBUSCLIENT_H_
