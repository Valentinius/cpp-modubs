#include "modbustcpclient.h"


ModbusTCPClient::ModbusTCPClient(std::string ip, uint16_t port, ModbusFramer framer): ModbusClient(ip, port, framer), asio_socket(asio_context) {
  this->asio_endpoint = asio::ip::tcp::endpoint(asio::ip::make_address(ip, this->asio_ec), this->port);
}

bool ModbusTCPClient::connect() {
  this->asio_ec.clear();
  this->asio_socket.connect(this->asio_endpoint, this->asio_ec);
  return !this->asio_ec;
}

bool ModbusTCPClient::connect(std::string ip, uint16_t port) {
  this->asio_ec.clear();
  this->asio_endpoint = asio::ip::tcp::endpoint(asio::ip::make_address(ip, this->asio_ec), port);
  return !this->asio_ec;
}

bool ModbusTCPClient::disconnect() {
  this->asio_ec.clear();
  this->asio_socket.close(this->asio_ec);
  return !this->asio_ec;
}
