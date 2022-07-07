#include "modbusrequest.h"

using modbus::utils::toMsbLsb;


ModbusRequest::ModbusRequest(uint16_t msb_reg,
                             uint16_t lsb_reg,
                             RegisterType register_type,
                             RequestPriority request_priority,
                             uint8_t slave_id,
                             uint32_t value) :
                             registers({msb_reg, lsb_reg}),
                             register_type(register_type),
                             request_priority(request_priority),
                             slave_id(slave_id),
                             request_type(RequestType::MULTIPLE_REGISTERS_WRITE),
                             request_status(RequestStatus::NOT_SENT){
  this->values.resize(2);
  toMsbLsb(value, this->values[0], this->values[1]);
}

ModbusRequest::ModbusRequest(uint16_t reg_num,
                             RegisterType register_type,
                             RequestPriority request_priority,
                             uint8_t slave_id,
                             uint16_t value) :
                             registers({reg_num}),
                             values({value}),
                             register_type(register_type),
                             request_priority(request_priority),
                             slave_id(slave_id),
                             request_type(RequestType::SINGLE_REGISTER_WRITE),
                             request_status(RequestStatus::NOT_SENT){

}

ModbusRequest::ModbusRequest(uint16_t reg_num,
                             uint8_t bit_num,
                             RegisterType register_type,
                             RequestPriority request_priority,
                             uint8_t slave_id,
                             bool bit_value):
                             registers({reg_num}),
                             values({bit_value}),
                             bit_num(bit_num),
                             register_type(register_type),
                             request_priority(request_priority),
                             slave_id(slave_id),
                             request_type(RequestType::PARTIAL_REGISTER_WRITE),
                             request_status(RequestStatus::NOT_SENT){
}

ModbusRequest::ModbusRequest(uint16_t msb_reg,
                             uint16_t lsb_reg,
                             RegisterType register_type,
                             RequestPriority request_priority,
                             uint8_t slave_id):
                             registers({msb_reg, lsb_reg}),
                             register_type(register_type),
                             request_priority(request_priority),
                             slave_id(slave_id),
                             request_type(RequestType::MULTIPLE_REGISTERS_READ),
                             request_status(RequestStatus::NOT_SENT) {

}

ModbusRequest::ModbusRequest(uint16_t reg_num,
                             RegisterType register_type,
                             RequestPriority request_priority,
                             uint8_t slave_id):
                             registers({reg_num}),
                             register_type(register_type),
                             request_priority(request_priority),
                             slave_id(slave_id),
                             request_type(RequestType::SINGLE_REGISTER_READ),
                             request_status(RequestStatus::NOT_SENT) {

}

ModbusRequest::ModbusRequest(uint16_t reg_num,
                             uint8_t bit_num,
                             RegisterType register_type,
                             RequestPriority request_priority,
                             uint8_t slave_id):
                             registers({reg_num}),
                             bit_num(bit_num),
                             register_type(register_type),
                             request_priority(request_priority),
                             slave_id(slave_id),
                             request_type(RequestType::MULTIPLE_REGISTERS_READ),
                             request_status(RequestStatus::NOT_SENT) {

}