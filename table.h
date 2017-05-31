#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QStandardItemModel>

namespace SDR2DXF {

/*******************************************************************/

class Table : public QWidget
{
    Q_OBJECT
private:
    QStandardItemModel *model;

    void setTitleModel();
public:
    Table(QWidget *parent = 0);
    virtual ~Table();
public slots:
    void clearTable();
};

/*******************************************************************/

} // namespace SDR2DXF

#endif // TABLE_H
