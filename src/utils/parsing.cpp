#include "parsing.h"

void modbus::utils::parseRequest(const std::shared_ptr<ModbusRequest> &modbus_request,
                                 uint8_t *raw_request,
                                 size_t raw_request_size) {

}

void modbus::utils::parseResponse(std::shared_ptr<ModbusRequest> &modbus_request,
                                  uint8_t *raw_response,
                                  size_t raw_response_size) {

}

ModbusError modbus::utils::parseError(uint8_t *raw_response, size_t raw_response_req) {

  return ModbusError::NO_ERROR;
}
