#ifndef FIGUR_H
#define FIGUR_H

#include <QBrush>
#include <QColor>
#include <QDebug>
#include <QRandomGenerator>

#include <array>
#include <iostream>
#include <vector>

#include "logger.h"
#include "unordered_map"

enum TYPE_DIRECTION : int { RIGHT = 0, LEFT = 1 };

class Figur {
public:
    void step(TYPE_DIRECTION dir);
    void down();
    std::array<std::pair<int, int>, 4> cell() { return _cell; }
    QColor color() { return figur_color; }
    //возвращает список клеток, которые требуют проверку по направлению (снизу, сверху, слева, справа)
    virtual std::vector<std::pair<int, int>> prov_down() = 0;
    virtual std::vector<std::pair<int, int>> prov_up() = 0;
    virtual std::vector<std::pair<int, int>> prov_left() = 0;
    virtual std::vector<std::pair<int, int>> prov_right() = 0;

protected:
    // row/col  row может хранить отрицательные значения, если фигура еще доконца не выехала
    std::array<std::pair<int, int>, 4> _cell;
    std::unordered_map<int, QColor> colorMap;
    QColor figur_color;

    std::vector<std::pair<int, int>> prov_cell(const std::vector<int> &list);
    void initColorMap();
};

//15 класса наследника (4 базовые формы, несколько поворотов)

class Figur_1 : public Figur {
public:
    Figur_1(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};

class Figur_2 : public Figur {
public:
    Figur_2(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_3 : public Figur {
public:
    Figur_3(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_4 : public Figur {
public:
    Figur_4(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_5 : public Figur {
public:
    Figur_5(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};

class Figur_6 : public Figur {
public:
    Figur_6(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_7 : public Figur {
public:
    Figur_7(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_8 : public Figur {
public:
    Figur_8(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};

class Figur_9 : public Figur {
public:
    Figur_9(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};

class Figur_10 : public Figur {
public:
    Figur_10(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_11 : public Figur {
public:
    Figur_11(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_12 : public Figur {
public:
    Figur_12(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_13 : public Figur {
public:
    Figur_13(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_14 : public Figur {
public:
    Figur_14(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};
class Figur_15 : public Figur {
public:
    Figur_15(int col);
    std::vector<std::pair<int, int>> prov_down();
    std::vector<std::pair<int, int>> prov_up();
    std::vector<std::pair<int, int>> prov_left();
    std::vector<std::pair<int, int>> prov_right();
};

class FigureFactory {
public:
    virtual Figur *createFigure(int col) = 0;
    virtual ~FigureFactory() {}
};

class RandomFigureFactory : public FigureFactory {
public:
    Figur *createFigure(int col) override
    {

        QRandomGenerator *generator = QRandomGenerator::global();
        int figureNum = generator->bounded(1, 15);
        qDebug() << " figure =" << figureNum;
        switch (figureNum) {
            case 1: return new Figur_1(col);
            case 2: return new Figur_2(col);
            case 3: return new Figur_3(col);
            case 4: return new Figur_4(col);
            case 5: return new Figur_5(col);
            case 6: return new Figur_6(col);
            case 7: return new Figur_7(col);
            case 8: return new Figur_8(col);
            case 9: return new Figur_9(col);
            case 10: return new Figur_10(col);
            case 11: return new Figur_11(col);
            case 12: return new Figur_12(col);
            case 13: return new Figur_13(col);
            case 14: return new Figur_14(col);
            case 15: return new Figur_15(col);
            default: return new Figur_9(col);
        }
    }
};

#endif // FIGUR_H
