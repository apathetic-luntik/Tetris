#include "logger.h"

Logger::Logger()
{
   // std::lock_guard<std::mutex> lock(mutex); //защита от одновременного доступа
    logFile.open("log.txt", std::ios::app); //открываем файл для записи логов
    if (!logFile.is_open()) {
        qDebug() << " Не удалось открыть файл";

    }
}

Logger::~Logger()
{
 //   std::lock_guard<std::mutex> lock(mutex); //защита от одновременного доступа
    if (!logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string &message)
{
  //  std::lock_guard<std::mutex> lock(mutex); //защита от одновременного доступа
    if (logFile.is_open()) {
        logFile << message << std::endl; //Запись сообщения в файл
    }
}
