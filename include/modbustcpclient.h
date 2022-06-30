#ifndef MODBUS_LIBRARY_CPP_INCLUDE_MODBUSTCPCLIENT_H_
#define MODBUS_LIBRARY_CPP_INCLUDE_MODBUSTCPCLIENT_H_

#include "modbusclient.h"

#include <string>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

using namespace boost;


class ModbusTCPClient: public ModbusClient {
 public:
  ModbusTCPClient(std::string ip, uint16_t port, ModbusFramer framer = ModbusFramer::RTU);

  bool connect() override;
  bool connect(std::string ip, uint16_t port) override;
  bool disconnect() override;

 private:
  system::error_code asio_ec;
  asio::io_context asio_context;
  asio::ip::tcp::socket asio_socket;
  asio::ip::tcp::endpoint asio_endpoint;
};

#endif //MODBUS_LIBRARY_CPP_INCLUDE_MODBUSTCPCLIENT_H_
