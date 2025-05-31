#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{

  auto screen = QGuiApplication::primaryScreen();
  QRect rect =screen->geometry();
    QPoint center = rect.center();

    int x1 = center.x() - this->geometry().width() / 4;
    int y1 = center.y() - this->geometry().height() / 2;
    int x2 = x1 + this->geometry().width();
    int y2 = y1 + this->geometry().height();

    auto geom = this->geometry();
    geom.setCoords(x1, y1, x2, y2);

    setGeometry(geom);

    ui->setupUi(this);

    timer = new QTimer;
    model = new TableModel;
    ui->tableView->setModel(model);

    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    connect(model, SIGNAL(ballSignal()), this, SLOT(ball()));
    connect(model, SIGNAL(gameOverSignal()), this, SLOT(gameOver()));
}

Widget::~Widget()
{
    delete model;
    delete timer;
    delete ui;
    Logger *logger = Logger::instance();
    logger->log(" Удаление игрового окна");
}

void Widget::on_start_clicked()
{
     Logger *logger = Logger::instance();
     logger->log(" Игра запущена");
    timer->start(speed);
    model->newFigure();
}

void Widget::on_zanovo_clicked()
{
 Logger *logger = Logger::instance();
    logger->log(" Игра перезапущена");
    timer->stop();
    //qDebug() << Q_FUNC_INFO;

    ui->scoreNum->setText("0");
    this->setEnabled(true);
    model->restart();
}

void Widget::slotTimerAlarm()
{
   // qDebug() << Q_FUNC_INFO;
    model->down();
}

void Widget::gameOver()
{

    timer->stop();
    this->setEnabled(false);
    //все фигурки становятся серыми

    auto score = ui->scoreNum->text();
     Logger *logger = Logger::instance();
    std::string st = " Конец игры со счетом " + score.toStdString();
     logger->log(st);
    QMessageBox *messageGameOver =
        new QMessageBox(QMessageBox::Information, "Тетрис",
                        "<p>    Конец игры!    </p> Счёт " + score, QMessageBox::Ok);

    messageGameOver->setIcon(QMessageBox::NoIcon);

    QSize size;
    size.setHeight(50);
    size.setWidth(180);

    messageGameOver->show();
    messageGameOver->setMinimumSize(size);

    int n = messageGameOver->exec();
    delete messageGameOver;

    if (n == QMessageBox::Ok || n == QMessageBox::Close)
        on_zanovo_clicked();
}

void Widget::ball()
{
    QString sl = ui->scoreNum->text();
    int newSL = sl.toInt();
    newSL++;
    ui->scoreNum->setText(sl.number(newSL));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

        case Qt::Key_Left: {
            qDebug() << " PressKey LEFT";
            model->steap(TYPE_DIRECTION::LEFT);

            break;
        }
        case Qt::Key_Right: {
            qDebug() << " PressKey RIGHT";
            model->steap(TYPE_DIRECTION::RIGHT);

            break;
        }
        case Qt::Key_Return: {

            if (!timer->isActive())
                on_start_clicked();
            qDebug() << " PressKey START";
            break;
        }
        default: return;
    }
}

void Widget::closeEvent(QCloseEvent *event)
{
    event->accept();
}
