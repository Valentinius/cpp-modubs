#include "utils.h"

void modbus::utils::crcRTU(const uint8_t *data, uint8_t size, uint8_t &msb, uint8_t &lsb) {
  uint16_t pos;
  uint16_t crc = 0xFFFF;

  for (pos = 0; pos < size; pos++){
    crc ^= (uint16_t)data[pos];          // XOR byte into least sig. byte of crc

    for (uint8_t i = 8; i != 0; i--){    // Loop over each bit
      if ((crc & 0x0001) != 0){      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }

  modbus::utils::toMsbLsb(crc, lsb, msb);
}

void modbus::utils::toMsbLsb(uint16_t data, uint8_t &lsb, uint8_t &msb) {
  lsb = data >> 8;
  msb = data & 0x00FF;
}

void modbus::utils::fromMsbLsb(uint8_t lsb, uint8_t msb, uint16_t &data) {
  data = lsb;
  data <<= 8;
  data = msb | data;
}

void modbus::utils::toMsbLsb(uint32_t data, uint16_t &lsb, uint16_t &msb) {
  lsb = data >> 16;
  msb = data & 0xFFFF;
}

void modbus::utils::fromMsbLsb(uint16_t lsb, uint16_t msb, uint32_t &data) {
  data = lsb;
  data <<= 16;
  data = msb | data;
}
