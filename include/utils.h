#ifndef UNTITLED1_INCLUDE_UTILS_H_
#define UNTITLED1_INCLUDE_UTILS_H_

namespace modbus {
  namespace enums {
    enum RequestStatus {
      SUCCESS = 0,
      CORRUPTED_DATA,
      TIMEOUT_ERROR
    };

    enum ModbusFramer {
      RTU,
      ASCII,
      TCP
    };

    enum RegisterType {
      DISCRETE_INPUTS,
      COILS,
      HOLDING_REGISTERS,
      INPUT_REGISTERS
    };
  }

  namespace utils {

  }
}
#endif //UNTITLED1_INCLUDE_UTILS_H_
