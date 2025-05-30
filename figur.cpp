#include "figur.h"

void Figur::step(TYPE_DIRECTION dir)
{
    switch (dir) {
        case TYPE_DIRECTION::RIGHT:
            _cell[0].second++;
            _cell[1].second++;
            _cell[2].second++;
            _cell[3].second++;

            return;
        case TYPE_DIRECTION::LEFT:
            _cell[0].second--;
            _cell[1].second--;
            _cell[2].second--;
            _cell[3].second--;
            return;
    }
}

void Figur::down()
{
    _cell[0].first++;
    _cell[1].first++;
    _cell[2].first++;
    _cell[3].first++;
}

std::vector<std::pair<int, int>> Figur::prov_cell(const std::vector<int> &list)
{
    std::vector<std::pair<int, int>> rez;
    for (size_t i = 0; i < list.size(); i++) {
        rez.push_back(_cell.at(list.at(i)));
    }

    return rez;
}

void Figur::initColorMap()
{
    colorMap[1] = QColor(0, 100, 200);
    colorMap[2] = QColor(200, 100, 0);
    colorMap[3] = QColor(0, 200, 100);
    colorMap[4] = QColor(200, 0, 100);
    colorMap[5] = QColor(100, 0, 200);
}

// Figu_1    *
//         ***
//-----------------------------------------------------------------------------

Figur_1::Figur_1(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 3);
    _cell[0].first = 0;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = 0;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = 0;

    _cell[3].second = _cell[2].second;
    _cell[3].first = -1;

    figur_color = colorMap.at(generator->bounded(1, 6));

    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 1");
}

std::vector<std::pair<int, int>> Figur_1::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_1::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(3);
    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_1::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_1::prov_right()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);
    return prov_cell(p);
}
// Figu_2  **
//          *
//          *
//-----------------------------------------------------------------------------

Figur_2::Figur_2(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 2);
    _cell[0].first = -2;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = -2;

    _cell[2].second = _cell[1].second;
    _cell[2].first = -1;

    _cell[3].second = _cell[1].second;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 2");
}

std::vector<std::pair<int, int>> Figur_2::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_2::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_2::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);
    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_2::prov_right()
{
    std::vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);
    return prov_cell(p);
}

// Figu_3   ***
//          *
//-----------------------------------------------------------------------------

Figur_3::Figur_3(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 3);
    _cell[0].first = 0;

    _cell[1].second = _cell[0].second;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = -1;

    _cell[3].second = _cell[2].second + 1;
    _cell[3].first = -1;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 3");
}

std::vector<std::pair<int, int>> Figur_3::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_3::prov_up()
{
    std::vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_3::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_3::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);
    return prov_cell(p);
}

// Figu_4   *
//          *
//          **
//-----------------------------------------------------------------------------

Figur_4::Figur_4(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 2);
    _cell[0].first = -2;

    _cell[1].second = _cell[0].second;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second;
    _cell[2].first = 0;

    _cell[3].second = _cell[2].second + 1;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 4");
}

std::vector<std::pair<int, int>> Figur_4::prov_down()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_4::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_4::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_4::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(3);
    return prov_cell(p);
}

// Figu_5   *
//          ***
//-----------------------------------------------------------------------------

Figur_5::Figur_5(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 3);
    _cell[0].first = -1;

    _cell[1].second = _cell[0].second;
    _cell[1].first = 0;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = 0;

    _cell[3].second = _cell[2].second + 1;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));

    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 5");
}

std::vector<std::pair<int, int>> Figur_5::prov_down()
{
    std::vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_5::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_5::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_5::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_6    *
//           *
//          **
//-----------------------------------------------------------------------------

Figur_6::Figur_6(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(1, col - 1);
    _cell[0].first = -2;

    _cell[1].second = _cell[0].second;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second;
    _cell[2].first = 0;

    _cell[3].second = _cell[2].second - 1;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 6");
}

std::vector<std::pair<int, int>> Figur_6::prov_down()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_6::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_6::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_6::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);

    return prov_cell(p);
}

// Figu_7   ***
//            *
//-----------------------------------------------------------------------------

Figur_7::Figur_7(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 3);
    _cell[0].first = -1;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = -1;

    _cell[3].second = _cell[2].second;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 7");
}

std::vector<std::pair<int, int>> Figur_7::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_7::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_7::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_7::prov_right()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_8   **
//          *
//          *
//-----------------------------------------------------------------------------

Figur_8::Figur_8(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(1, col - 1);
    _cell[0].first = -2;

    _cell[1].second = _cell[0].second - 1;
    _cell[1].first = -2;

    _cell[2].second = _cell[1].second;
    _cell[2].first = -1;

    _cell[3].second = _cell[2].second;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 8");
}

std::vector<std::pair<int, int>> Figur_8::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_8::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_8::prov_left()
{
    std::vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_8::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
// Figu_9  **
//         **
//-----------------------------------------------------------------------------

Figur_9::Figur_9(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 2);
    _cell[0].first = -1;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = -1;

    _cell[2].second = _cell[0].second;
    _cell[2].first = 0;

    _cell[3].second = _cell[1].second;
    _cell[3].first = 0;
    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 9");
}

std::vector<std::pair<int, int>> Figur_9::prov_down()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_9::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_9::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_9::prov_right()
{
    std::vector<int> p;
    p.push_back(1);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_10   *
//         ***
//-----------------------------------------------------------------------------

Figur_10::Figur_10(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 3);
    _cell[0].first = 0;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = 0;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = 0;

    _cell[3].second = _cell[1].second;
    _cell[3].first = -1;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 10");
}

std::vector<std::pair<int, int>> Figur_10::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_10::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_10::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_10::prov_right()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_11   *
//          **
//           *
//-----------------------------------------------------------------------------

Figur_11::Figur_11(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(1, col - 1);
    _cell[0].first = -2;

    _cell[1].second = _cell[0].second;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second;
    _cell[2].first = 0;

    _cell[3].second = _cell[1].second - 1;
    _cell[3].first = -1;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 11");
}

std::vector<std::pair<int, int>> Figur_11::prov_down()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_11::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_11::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_11::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);

    return prov_cell(p);
}
// Figu_12  ***
//           *
//-----------------------------------------------------------------------------

Figur_12::Figur_12(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 3);
    _cell[0].first = -1;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = -1;

    _cell[3].second = _cell[1].second;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 12");
}

std::vector<std::pair<int, int>> Figur_12::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_12::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_12::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_12::prov_right()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_13   *
//          **
//           *
//-----------------------------------------------------------------------------

Figur_13::Figur_13(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 2);
    _cell[0].first = -2;

    _cell[1].second = _cell[0].second;
    _cell[1].first = -1;

    _cell[2].second = _cell[1].second;
    _cell[2].first = 0;

    _cell[3].second = _cell[1].second + 1;
    _cell[3].first = -1;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 13");
}

std::vector<std::pair<int, int>> Figur_13::prov_down()
{
    std::vector<int> p;
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_13::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_13::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_13::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_14   *
//           *
//           *
//           *
//-----------------------------------------------------------------------------

Figur_14::Figur_14(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 1);
    _cell[0].first = -3;

    _cell[1].second = _cell[0].second;
    _cell[1].first = -2;

    _cell[2].second = _cell[1].second;
    _cell[2].first = -1;

    _cell[3].second = _cell[2].second;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 14");
}

std::vector<std::pair<int, int>> Figur_14::prov_down()
{
    std::vector<int> p;
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_14::prov_up()
{
    std::vector<int> p;
    p.push_back(0);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_14::prov_left()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_14::prov_right()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}

// Figu_15   ****
//-----------------------------------------------------------------------------

Figur_15::Figur_15(int col)
{
    initColorMap();
    QRandomGenerator *generator = QRandomGenerator::global();

    _cell[0].second = generator->bounded(0, col - 4);
    _cell[0].first = 0;

    _cell[1].second = _cell[0].second + 1;
    _cell[1].first = 0;

    _cell[2].second = _cell[1].second + 1;
    _cell[2].first = 0;

    _cell[3].second = _cell[2].second + 1;
    _cell[3].first = 0;

    figur_color = colorMap.at(generator->bounded(1, 6));
    // Logger *logger = Logger::instance();
    // logger->log(" Создана новая фигура 15");
}

std::vector<std::pair<int, int>> Figur_15::prov_down()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_15::prov_up()
{
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_15::prov_left()
{
    std::vector<int> p;
    p.push_back(0);

    return prov_cell(p);
}
std::vector<std::pair<int, int>> Figur_15::prov_right()
{
    std::vector<int> p;
    p.push_back(3);

    return prov_cell(p);
}
