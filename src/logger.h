#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#include <fstream>
//#include <iostream>
#include <mutex>
#include <string>

class Logger {
private:
    static inline Logger *_instance = nullptr; //Указатель на единственный экземпляр
 static inline std::mutex mutex; //Мьютекс для потокобезопасности (в этой программе
    //один поток, но так как это класс одиночка, у него
    // лучше написать, вдруг в будующем будет переделываться
    //под многопоточку, кто знает)
    std::ofstream logFile; //Файл для записи логов

    Logger();
    ~Logger();

public:
    static Logger *instance()
    {
        qDebug()<< Q_FUNC_INFO;
        // погуглить про это побольше, делала в последний момент
        std::lock_guard<std::mutex> lock(mutex); //защита от одновременного доступа

        if (_instance == nullptr) {
            _instance = new Logger();
        }

        return _instance;
    }
    void log(const std::string &message);
};

#endif // LOGGER_H
