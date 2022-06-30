#include "utils.h"

void modbus::utils::crc(const uint8_t *data, uint8_t size, uint8_t &msb, uint8_t &lsb) {
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

  lsb = crc >> 8;
  msb = crc & 0x00FF;
}