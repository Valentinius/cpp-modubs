#ifndef UNTITLED1_INCLUDE_UTILS_H_
#define UNTITLED1_INCLUDE_UTILS_H_

#include <cstdint>

namespace modbus {
  namespace enums {
    enum RequestStatus {
      SUCCESS = 0,
      CORRUPTED_DATA,
      TIMEOUT_ERROR
    };

    enum ModbusFramer {
      RTU = 0,
      ASCII = 1,
      TCP = 2
    };

    enum RegisterType {
      DISCRETE_INPUTS,
      COILS,
      HOLDING_REGISTERS,
      INPUT_REGISTERS
    };

    enum ModbusFunction {
      READ_DISCRETE_INPUTS_GROUP = 0x02,
      READ_COILS_GROUP = 0x01,
      READ_INPUTS_GROUP = 0x04,
      READ_HOLDING_REGISTERS_GROUP = 0x03,
      WRITE_COILS_ONE = 0x05,
      WRITE_COILS_GROUP = 0x0F,
      WRITE_HOLDING_REGISTERS_ONE = 0x06,
      WRITE_HOLDING_REGISTERS_GROUP = 0x10
    };
  }

  namespace utils {
  /**
   * Kukukaudsl kasudlkjqwo djoqwjdojj jj
   * @param data dlkqwjdlqjdw;lxkcj a;s
   * @param size fqwlkejlkqw
   * @param msb
   * @param lsb
   */
    void crc(const uint8_t *data, uint8_t size, uint8_t &msb, uint8_t &lsb);
  }
}
#endif //UNTITLED1_INCLUDE_UTILS_H_
