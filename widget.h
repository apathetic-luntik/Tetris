#ifndef WIDGET_H
#define WIDGET_H

#include <QMessageBox>
#include <QWidget>
#include <QtWidgets>
#include <QDesktopServices>

#include "tablemodel.h"

namespace Ui {
class Widget; //класс отображения диалогового окна
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui; //надо загуглить стандартная фигня (экземпляр класса, более умно в гугле)
    TableModel *model; //экземпляр модели игрового поля (таблицы)
    QTimer *timer;     //экземпляр таймера, для отсчета шага
    const int speed = 200; //скорость работы тайлера мс

    void keyPressEvent(QKeyEvent *event); // обработка нажатия на клавиши
    void closeEvent(QCloseEvent *event); //обработка закрытия окна

private slots:
    //слот для обработки сигнала "конец игры"
    void gameOver();

    //слот для обработки сигнала "начисление балла" (пы.сы. мне стало уже лень идти к переводчику)
    void ball();

    //слот после каждого цикла таймера
    void slotTimerAlarm();

    //слот обработки нажатия на кнопку "старт"
    void on_start_clicked();

    //слот обработки нажатия на кнопку "заново"
    void on_zanovo_clicked();
};

#endif // WIDGET_H
