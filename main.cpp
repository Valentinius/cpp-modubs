#include <unistd.h>
#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

using namespace boost;

int make_stream_from_buffer(asio::streambuf &asio_buffer, uint8_t *buff, size_t buff_size);
void make_buffer_from_stream(asio::streambuf &asio_buffer, uint8_t *buff, size_t buff_size);
void handler(const boost::system::error_code ec, std::size_t bytes_transfered);

uint16_t crc(uint8_t *data, uint8_t size, uint8_t &msb, uint8_t &lsb);


int main(int argc, char *argv[]) {
  boost::system::error_code ec;

  asio::io_context context;
  asio::ip::tcp::endpoint endpoint(asio::ip::make_address("192.168.127.10", ec), 4001);

  asio::ip::tcp::socket socket(context);

  socket.connect(endpoint, ec);

  if (!ec) std::cout << "Connected!" << std::endl;
  else std::cout << "Failed!" << std::endl;

  if (socket.is_open()) {
    uint8_t buffer[6] {
        0x01, 0x03, 0x00, 0x00, 0x00, 0x4
    };
//    uint8_t buffer[6] {
//        0x01, 0x06, 0x00, 0x1C, 0x00, 0x01
//    };

    uint8_t buffer_with_crc[8];
    for (int i = 0; i < 6; i++) buffer_with_crc[i] = std::move(buffer[i]);

    crc(buffer, 6, buffer_with_crc[6], buffer_with_crc[7]);
    std::cout << unsigned(buffer_with_crc[6]) << " " << unsigned(buffer_with_crc[7]) << std::endl;

    asio::streambuf asio_buffer;
    uint8_t read_buffer[16];
    for (int i = 0; i < 16; i++) read_buffer[i] = -5;

    int size = make_stream_from_buffer(asio_buffer, buffer_with_crc, 8);

//    socket.write_some(asio_buffer.data(), ec);
    socket.async_write_some(asio_buffer.data(), handler);
    size_t bytes = socket.available();
    std::cout << bytes << std::endl;

//    socket.read_some(asio::buffer(read_buffer), ec);
    socket.async_read_some(asio::buffer(read_buffer), &handler);
    sleep(5);

    for (auto i: read_buffer) std::cout << unsigned(i) << " ";
    std::cout << std::endl;
  }
  return 0;
}

void handler(const boost::system::error_code ec, std::size_t bytes_transfered){
  std::cout << "Shit" << bytes_transfered << std::endl;
}

int make_stream_from_buffer(asio::streambuf &asio_buffer, uint8_t *buff, size_t buff_size) {
  auto out = std::ostreambuf_iterator<char>(&asio_buffer);
  for (size_t i = 0; i < buff_size; i++)
    *out++ = buff[i];

  return buff_size;
}


void make_buffer_from_stream(asio::streambuf &asio_buffer, uint8_t *buff, size_t buff_size) {
  // buff = asio::buffer_cast<uint8_t*>(asio_buffer.data());
}

uint16_t crc(uint8_t *data, uint8_t size, uint8_t &msb, uint8_t &lsb) {
  uint16_t pos;
  uint8_t i;
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

  std::cout << unsigned(crc) << std::endl;
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}
