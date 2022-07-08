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


/**
 * Класс, характеризующий сессия MODBUS
 */
class ModbusSession {
 public:
  ModbusSession();

  /**
   *
   * Метод для добавление MODBUS клиента явно. Причем клиентами могут быть все те объекты, классы которых
   * являются наследниками абстрактного класса ModbusClient. Это позволяет в случае чего работать сразу с TCP/IP,
   * а также, например, RS-232
   * @param modbus_client - указатель на клиент
   * @return индекс добавленного клиента в векторе клиентов сессии. Он необходим для того, чтобы
   * в дальнейшем обращаться к данному клиенту через сессию.
   */
  size_t addClient(std::shared_ptr<ModbusClient> modbus_client);

  /**
   * Метод для добавление MODBUS TCP клиента явно (без необходимости до этого создавать его объект)
   * @param ip - ip адрес modbus устройства
   * @param port - порт modbus устройства
   * @param modbus_framer - обертка, служащая для формирования пакета MODBUS
   * @return индекс добавленного клиента в векторе клиентов сессии. Он необходим для того, чтобы
   * в дальнейшем обращаться к данному клиенту через сессию.
   */
  size_t addClient(std::string ip, uint16_t port, ModbusFramerType modbus_framer);

  /**
   * Удаление клиента из сесии по его указателю
   * \warning Не рекомендуется использовать этот метод, так как он работает дольше
   * чем его перегрузка, которая удаляет клиента по индексу
   * @param modbus_client - указатель на клиент
   */
  void removeClient(std::shared_ptr<ModbusClient> modbus_client);

  /**
   * Удаление клиента из сессии по его индексу в векторе клиентов сессии
   * @param client_num - индекс клиента
   */
  void removeClient(int client_num);

  /**
   * Метод для запуска сессии.
   * @return вектор логических переменных, показывающих, установлено ли корректное подключение
   * с клиентами в ходе запуска сесии или нет
   */
  std::vector<bool> run();

  /**
   * Метод для остановки сессии. До остановки должны заверщиться все запросы, которые было в сессии до того,
   * как был вызван этот метод. Запросы, добавленные в сессию после вызова этого метода и до завершения сессии
   * исполнены не будут
   */
  void stop();

  /**
   * Метод для быстрой остановке сессии. Сессия завершается сразу
   * \warning Рекомендуется использовать этот метод только в тех случаях, когда он действительно необходим
   */
  void terminate();

  /**
   * Метод для добавления запроса в сессию.
   * @param request - указатель на объект запроса
   * @param client_num - индекс клиента в векторе клиентов сесии
   * @return указатель на объект запроса
   */
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
