#ifndef MODBUS_LIBRARY_CPP_INCLUDE_MODBUSREQUEST_H_
#define MODBUS_LIBRARY_CPP_INCLUDE_MODBUSREQUEST_H_

#include <utility>
#include <vector>
#include <memory>
#include <functional>
#include <future>

#include "utils.h"

using modbus::enums::RequestStatus;
using modbus::enums::RequestType;
using modbus::enums::RequestPriority;
using modbus::enums::RegisterType;


class ModbusRequest {
  friend class ModbusRequestComparator;

 public:
  ModbusRequest(uint16_t msb_reg,
                uint16_t lsb_reg,
                RegisterType register_type,
                RequestPriority request_priority,
                uint8_t slave_id,
                uint32_t value);

  ModbusRequest(uint16_t reg_num,
                RegisterType register_type,
                RequestPriority request_priority,
                uint8_t slave_id,
                uint16_t value);

  ModbusRequest(uint16_t reg_num,
                uint8_t byte_num,
                RegisterType register_type,
                RequestPriority request_priority,
                uint8_t slave_id,
                bool byte_value);

  ModbusRequest(uint16_t msb_reg,
                uint16_t lsb_reg,
                RegisterType register_type,
                RequestPriority request_priority,
                uint8_t slave_id);

  ModbusRequest(uint16_t reg_num,
                RegisterType register_type,
                RequestPriority request_priority,
                uint8_t slave_id);

  ModbusRequest(uint16_t reg_num,
                uint8_t byte_num,
                RegisterType register_type,
                RequestPriority request_priority,
                uint8_t slave_id);


  inline RequestType getRequestType() const {
    return this->request_type;
  }

  inline RequestStatus getRequestStatus() const {
    return this->request_status;
  };

  inline RequestPriority getRequestPriority() const {
    return this->request_priority;
  };

  inline RegisterType getRegisterType() const {
    return this->register_type;
  };

  inline uint8_t getSlaveId() const {
    return this->slave_id;
  };

  inline const std::vector<uint16_t>& getRegisters() const {
    return this->registers;
  };

  inline bool getValues(std::vector<uint16_t> &values) const {
    if (this->future_async) {
      this->future_async->get();
      values = this->values;
      return true;
    }
    return false;
  };

  inline void setValue(size_t value) {
    this->value = value;
  };

  inline void setRequestStatus(RequestStatus request_status) {
    this->request_status = request_status;
  };

  inline void setSentCallback(std::function<void(const std::shared_ptr<ModbusRequest>&)> callback) {
    this->sent_callback = std::move(callback);
  };

  inline void setResponsedCallback(std::function<void(const std::shared_ptr<ModbusRequest>&)> callback) {
    this->responsed_callback = std::move(callback);
  };

  inline void setTimeoutCallback(std::function<void(const std::shared_ptr<ModbusRequest>&)> callback) {
    this->timeout_callback = std::move(callback);
  };

  inline void setFutureAsync(std::shared_ptr<std::future<void>> &future_async) {
    this->future_async = future_async;
  };

 private:
  const RequestType request_type;
  RequestStatus request_status;
  const RequestPriority request_priority;
  const RegisterType register_type;
  const uint8_t slave_id;

  const std::vector<uint16_t> registers;
  std::vector<uint16_t> values;
  uint8_t bit_num;

  std::function<void(const std::shared_ptr<ModbusRequest>&)> sent_callback;
  std::function<void(const std::shared_ptr<ModbusRequest>&)> responsed_callback;
  std::function<void(const std::shared_ptr<ModbusRequest>&)> timeout_callback;

  std::shared_ptr<std::future<void>> future_async;
};

class ModbusRequestComparator {
 public:
  inline bool operator() (const std::shared_ptr<ModbusRequest>& request1,
                          const std::shared_ptr<ModbusRequest>& request2) {
    return request1->request_priority > request2->request_priority;
  };
};


#endif //MODBUS_LIBRARY_CPP_INCLUDE_MODBUSREQUEST_H_
