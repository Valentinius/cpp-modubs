#ifndef MODBUS_LIBRARY_CPP_INCLUDE_FRAMERS_MODBUSFRAMER_H_
#define MODBUS_LIBRARY_CPP_INCLUDE_FRAMERS_MODBUSFRAMER_H_

#include "utils.h"

#include <memory>

#include "modbusrequest.h"

using modbus::enums::ModbusFramerType;
using modbus::enums::ModbusError;


class ModbusFramer {
 public:
  virtual void parseRequest(const std::shared_ptr<ModbusRequest> &request,
                            uint8_t *raw_request,
                            size_t &raw_request_size);
  virtual void parseResponse(std::shared_ptr<ModbusRequest> &request,
                             uint8_t *raw_request,
                             size_t raw_request_size);

  virtual ModbusError parseError(uint8_t *raw_request, size_t raw_request_size);
 private:

  bool parseSingleRegisterWriteRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);
  bool parseMultipleRegistersWriteRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);
  bool parsePartialRegisterWriteRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);
  bool parseSingleRegisterReadRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);
  bool parseMultipleRegistersReadRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);
  bool parsePartialRegisterReadRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);

  bool parseReadRequest(const std::shared_ptr<ModbusRequest> &request, uint8_t *raw_request);
};

#endif //MODBUS_LIBRARY_CPP_INCLUDE_FRAMERS_MODBUSFRAMER_H_
