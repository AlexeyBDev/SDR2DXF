#include "table.h"

#include <QHBoxLayout>
#include <QTableView>

namespace SDR2DXF {

/*******************************************************************/

Table::Table(QWidget *parent) : QWidget(parent)
{
    // global var
    int margin = 5;

    QHBoxLayout *BoxTable = new QHBoxLayout(this);
    BoxTable->setMargin(margin);

    int raw = 5; // для начала одна строка
    int col = 5; // Name - X - Y - H - Code

    model = new QStandardItemModel(raw, col, this);

    QTableView *Tv = new QTableView(this);
    Tv->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("X"));
    model->setHeaderData(2, Qt::Horizontal, tr("Y"));
    model->setHeaderData(3, Qt::Horizontal, tr("H"));
    model->setHeaderData(4, Qt::Horizontal, tr("Code"));
    // пример заполнения таблицы
    QModelIndex index;
    {
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int col = 0; col < model->columnCount(); ++col) {
                index = model->index(row, col);
                //float var = model->data(index).toFloat();
                model->setData(index, 5);
                //model->clear();
            }
        }
    }

    BoxTable->addWidget(Tv);
}

/*******************************************************************/

Table::~Table() {

}

/*******************************************************************/

void Table::setTitleModel() {
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
//    setHeaderData(1, Qt::Horizontal, tr("X"));
//    setHeaderData(2, Qt::Horizontal, tr("Y"));
//    setHeaderData(3, Qt::Horizontal, tr("H"));
//    setHeaderData(4, Qt::Horizontal, tr("Code"));
}

/*******************************************************************/

void Table::clearTable() {
    model->clear();
    //setTitleModel();
}

/*******************************************************************/

} // namespace SDR2DXF
