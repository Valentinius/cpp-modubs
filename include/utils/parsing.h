#ifndef MODBUS_LIBRARY_CPP_INCLUDE_PARSING_H_
#define MODBUS_LIBRARY_CPP_INCLUDE_PARSING_H_

#include "modbusrequest.h"
#include "utils.h"

using modbus::enums::ModbusError;

namespace modbus {
  namespace utils {
    void parseRequest(const std::shared_ptr<ModbusRequest> &modbus_request,
                        uint8_t *raw_request,
                        size_t raw_request_size);

    void parseResponse(std::shared_ptr<ModbusRequest> &modbus_request,
                         uint8_t *raw_response,
                         size_t raw_response_size);

     ModbusError parseError(uint8_t *raw_response,
                              size_t raw_response_req);
  }
}

#endif //MODBUS_LIBRARY_CPP_INCLUDE_PARSING_H_