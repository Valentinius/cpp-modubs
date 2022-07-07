#ifndef MODBUS_LIBRARY_CPP_INCLUDE_MODBUSSESSION_H_
#define MODBUS_LIBRARY_CPP_INCLUDE_MODBUSSESSION_H_

#include <queue>
#include <vector>
#include <memory>
#include <string>
#include <future>

#include "modbusrequest.h"
#include "modbusclient.h"
#include "utils.h"

using modbus::enums::ModbusFramerType;


class ModbusSession {
 public:
  ModbusSession();
  void addClient(std::shared_ptr<ModbusClient> modbus_client);
  void addClient(std::string ip, uint16_t port, ModbusFramerType modbus_framer);
  void removeClient(std::shared_ptr<ModbusClient> modbus_client);
  void removeClient(int client_num);

  std::vector<bool> run();
  void stop();
  void terminate();

  std::shared_ptr<ModbusRequest> addRequest(std::shared_ptr<ModbusRequest> request, size_t client_num);

 private:
  std::vector<std::priority_queue<std::shared_ptr<ModbusRequest>,
      std::vector<std::shared_ptr<ModbusRequest>>, ModbusRequestComparator>> request_queues;
  std::vector<std::shared_ptr<ModbusClient>> clients;

  std::shared_ptr<std::future<void>> future_run_async;

  void _run();

  void _multipleRegistersReadProcess(const std::shared_ptr<ModbusRequest>& request,
                                     const std::vector<uint16_t> &registers,
                                     size_t client_id,
                                     std::vector<uint8_t> &request_result);
  void _singleRegisterReadProcess(const std::shared_ptr<ModbusRequest>& request,
                                  const std::vector<uint16_t> &registers,
                                  size_t client_id,
                                  std::vector<uint8_t> &request_result);
  void _partialRegistersReadProcess(const std::shared_ptr<ModbusRequest>& request,
                                    const std::vector<uint16_t> &registers,
                                    size_t client_id,
                                    std::vector<uint8_t> &request_result);
  void _multipleRegistersWriteProcess(const std::shared_ptr<ModbusRequest>& request,
                                      const std::vector<uint16_t> &registers,
                                      size_t client_id,
                                      std::vector<uint8_t> &request_result);
  void _singleRegisterWriteProcess(const std::shared_ptr<ModbusRequest>& request,
                                   const std::vector<uint16_t> &registers,
                                   size_t client_id,
                                   std::vector<uint8_t> &request_result);
  void _partialRegistersWriteProcess(const std::shared_ptr<ModbusRequest>& request,
                                     const std::vector<uint16_t> &registers,
                                     size_t client_id,
                                     std::vector<uint8_t> &request_result);
};

#endif //MODBUS_LIBRARY_CPP_INCLUDE_MODBUSSESSION_H_
