#include "logger.h"

Logger::Logger()
{

    logFile.open("log.txt", std::ios::app); //открываем файл для записи логов
    if (!logFile.is_open()) {
        qDebug() << " Не удалось открыть файл";
        //добавить создание файла, если его нет
    }
}

Logger::~Logger()
{
    if (!logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string &message)
{
    if (logFile.is_open()) {
        logFile << message << std::endl; //Запись сообщения в файл
    }
}
