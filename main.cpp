#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[])
{
    //  Logger *logger = Logger::instance();
    // logger->log(" Программа запущена ");
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
