#ifndef FILEELEMEN_H
#define FILEELEMEN_H

#include <QLineEdit>
#include <QFileDialog>

namespace SDR2DXF {

/*******************************************************************/

class fileElemen : public QWidget
{
    Q_OBJECT
protected:
    QLineEdit *leInput;
    QLineEdit *leOutput;
    QString inputFileName;
    QString outputFileName;
public:
    fileElemen(QWidget *perent = 0);
    virtual ~fileElemen();
public slots:
    void openFileSlot();
    void saveFileSlot();

    void clearInputLineEdit();
    void clearOutputLineEdit();
};

} // namespace SDR2DXF

/*******************************************************************/

#endif // FILEELEMEN_H
