#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#include <fstream>
#include <iostream>
#include <mutex>
#include <string>

class Logger {
private:
    static Logger *_instance; //Указатель на единственный экземпляр
    static std::mutex mutex; //Мьютекс для потокобезопасности (в этой программе
    //один поток, но так как это класс одиночка, у него
    // лучше написать, вдруг в будующем будет переделываться
    //под многопоточку, кто знает)
    std::ofstream logFile; //Файл для записи логов

    Logger();
    ~Logger();

public:
    static Logger *instance()
    {
        // погуглить про это побольше, делала в последний момент
        std::lock_guard<std::mutex> lock(mutex); //защита от одновременного доступа
                                                 // mutex.lock();
        if (_instance == nullptr) {
            _instance = new Logger();
        }
        return _instance;
    }
    void log(const std::string &message);
};

#endif // LOGGER_H
