#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QStandardItemModel>

#include "figur.h"

enum class TYPE_CELL { EMPTY = 0, FIGUR = 1 };

class TypeCell {
public:
    TYPE_CELL type;
};

Q_DECLARE_METATYPE(TypeCell)

class TableModel : public QStandardItemModel {
    Q_OBJECT
public:
    TableModel();
    //шаг вниз
    void down();

    //шаг в сторону
    // dir - направление сдвига
    void steap(TYPE_DIRECTION dir);

    // создание новой фигуры
    void newFigure();

    // обновление всей модели до стартовой
    void restart();
    ~TableModel();

private:
    //ссылка на фигура
    Figur *_figure = nullptr;
    //ссылка на фабрику
    FigureFactory *factory;

    //проверка, что клетки не заняты другой фигурой
    bool cellFigure();
    //проверка, что есть куда падать вниз
    bool downCellWall();
    //проверка, сверху нет, потолка
    bool upCellWall();
    bool cboky(TYPE_DIRECTION dir);
    void checkRow();
    void clearRow(size_t row);
    void paint(const std::array<std::pair<int, int>, 4> &figur, TYPE_CELL type);
signals:
    void gameOverSignal();
    void ballSignal();
};

#endif // TABLEMODEL_H
