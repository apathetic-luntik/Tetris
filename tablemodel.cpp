#include "tablemodel.h"

TableModel::TableModel()
{

    factory = new RandomFigureFactory();
    int col = 10;
    int row = 15;
    // Logger *logger = Logger::instance();
    std::string st = "Создан класс TableModel: размер поля " + std::to_string(col) + "X" +
                     std::to_string(row);
    // logger->log(st);
    setRowCount(row);
    setColumnCount(col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            QStandardItem *item = new QStandardItem;
            QVariant newItem;

            TypeCell type;
            type.type = TYPE_CELL::EMPTY;
            newItem.setValue(type);

            item->setData(newItem);
            item->setBackground(Qt::white);
            setItem(i, j, item);
        }
}

TableModel::~TableModel()
{
    delete factory;
    if (_figure != nullptr)
        delete _figure;
}

void TableModel::restart()
{
    qDebug() << Q_FUNC_INFO;
    size_t col = columnCount();
    size_t row = rowCount();
    if (_figure != nullptr) {
        delete _figure;
        _figure = nullptr;
    }
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++) {
            auto item = this->item(i, j);
            QVariant newItem;
            TypeCell type;
            type.type = TYPE_CELL::EMPTY;
            newItem.setValue(type);
            item->setData(newItem);
            item->setBackground(Qt::white);
            setItem(i, j, item);
        }
}

void TableModel::paint(const std::array<std::pair<int, int>, 4> &fig, TYPE_CELL typeFig)
{
    qDebug() << Q_FUNC_INFO;

    for (size_t i = 0; i < fig.size(); i++) {
        auto row = fig.at(i).first;
        auto col = fig.at(i).second;
        //        qDebug() << "row = " << row << " col =" << col;
        if (row < 0)
            continue;
        if (col < 0)
            continue;

        auto item = this->item(row, col);

        QVariant newItem;

        TypeCell type;
        type.type = typeFig;
        newItem.setValue(type);
        item->setData(newItem);
        //костыль
        if (typeFig == TYPE_CELL::EMPTY)
            item->setBackground(Qt::white);
        if (typeFig == TYPE_CELL::FIGUR)
            item->setBackground(_figure->color());
        setItem(row, col, item);
    }
}

void TableModel::down()
{
    qDebug() << Q_FUNC_INFO;

    if (_figure != nullptr) {

        if (downCellWall()) {
            checkRow();
            if (upCellWall()) {
                emit gameOverSignal();
                return;
            }

            delete _figure;
            _figure = nullptr;

            newFigure();
            return;
        }
        paint(_figure->cell(), TYPE_CELL::EMPTY);
        _figure->down();
        paint(_figure->cell(), TYPE_CELL::FIGUR);
    }
}

bool TableModel::cellFigure()
{
    qDebug() << Q_FUNC_INFO;
    auto fig = _figure->cell();
    for (size_t i = 0; i < fig.size(); i++) {
        auto cell = fig.at(i);
        if (cell.first < 0)
            continue;
        auto item = this->item(cell.first, cell.second);
        auto data = item->data();
        auto celltype = data.value<TypeCell>();

        if (celltype.type == TYPE_CELL::FIGUR)
            return true;
    }
    return false;
}

bool TableModel::downCellWall()
{
    qDebug() << Q_FUNC_INFO;
    auto fig = _figure->prov_down();
    for (size_t i = 0; i < fig.size(); i++) {
        auto cell = fig.at(i);

        if (cell.first == (rowCount() - 1))
            return true;
        if (cell.first < 0)
            continue;
        auto item = this->item((cell.first + 1), cell.second);
        auto data = item->data();
        auto celltype = data.value<TypeCell>();

        if (celltype.type == TYPE_CELL::FIGUR)
            return true;
    }
    return false;
}

bool TableModel::upCellWall()
{
    qDebug() << Q_FUNC_INFO;
    auto fig = _figure->prov_up();
    for (size_t i = 0; i < fig.size(); i++) {
        auto cell = fig.at(i);
        if (cell.first < 0)
            return true;
    }
    return false;
}

bool TableModel::cboky(TYPE_DIRECTION dir)
{
    qDebug() << Q_FUNC_INFO;
    if (dir == TYPE_DIRECTION::LEFT) {
        auto fig = _figure->prov_left();
        for (size_t i = 0; i < fig.size(); i++) {
            auto cell = fig.at(i);
            if (cell.second == 0)
                return true;
            if (cell.first < 0)
                continue;

            auto item = this->item(cell.first, (cell.second - 1));
            auto data = item->data();
            auto celltype = data.value<TypeCell>();

            if (celltype.type == TYPE_CELL::FIGUR)
                return true;
        }
        return false;
    }

    if (dir == TYPE_DIRECTION::RIGHT) {
        auto fig = _figure->prov_right();
        for (size_t i = 0; i < fig.size(); i++) {
            auto cell = fig.at(i);
            if (cell.second == (columnCount() - 1))
                return true;
            if (cell.first < 0)
                continue;

            auto item = this->item(cell.first, (cell.second + 1));
            auto data = item->data();
            auto celltype = data.value<TypeCell>();

            if (celltype.type == TYPE_CELL::FIGUR)
                return true;
        }
        return false;
    }
    return false;
}

void TableModel::steap(TYPE_DIRECTION dir)
{
    qDebug() << Q_FUNC_INFO;
    if (_figure != nullptr) {
        if (cboky(dir))
            return;
        paint(_figure->cell(), TYPE_CELL::EMPTY);
        _figure->step(dir);
        paint(_figure->cell(), TYPE_CELL::FIGUR);
    }
}

void TableModel::clearRow(size_t row)
{
    qDebug() << Q_FUNC_INFO;
    //    qDebug() << "row = " << row;
    size_t col = columnCount();

    for (size_t j = 0; j < col; j++) {
        auto item = this->item(row, j);
        QVariant newItem;
        TypeCell type;
        type.type = TYPE_CELL::EMPTY;
        newItem.setValue(type);
        item->setData(newItem);
        item->setBackground(Qt::white);
        setItem(row, j, item);
    }
    for (size_t j = 0; j < col; j++)

        for (int i = row; i >= 0; i--) {
            auto item = this->item(i, j);
            auto data = item->data();
            auto celltype = data.value<TypeCell>();

            if (celltype.type == TYPE_CELL::FIGUR) {
                auto itemNew = this->item(i + 1, j);
                QVariant newItem;
                TypeCell type;
                type.type = TYPE_CELL::FIGUR;
                newItem.setValue(type);
                itemNew->setData(newItem);
                itemNew->setBackground(item->background());
                setItem(i + 1, j, itemNew);

                type.type = TYPE_CELL::EMPTY;
                newItem.setValue(type);
                item->setData(newItem);
                item->setBackground(Qt::white);
                setItem(i, j, item);
            }
        }
}

void TableModel::checkRow()
{
    qDebug() << Q_FUNC_INFO;
    size_t col = columnCount();
    size_t row = rowCount();
    //    qDebug() << "col = " << col << " row =" << row;
    for (size_t i = 0; i < row; i++) {
        size_t j = 0;
        for (j; j < col; j++) {
            auto item = this->item(i, j);
            auto data = item->data();
            auto celltype = data.value<TypeCell>();

            if (celltype.type == TYPE_CELL::EMPTY) {

                break;
            }
        }
        if (j == col) {
            clearRow(i);
            emit ballSignal();
        }
    }
}

void TableModel::newFigure()
{
    qDebug() << Q_FUNC_INFO;
    if (_figure == nullptr) {
        _figure = factory->createFigure(columnCount());
        if (cellFigure())
            return;
        paint(_figure->cell(), TYPE_CELL::FIGUR);
    }
}
