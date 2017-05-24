#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QFileDialog>
#include <QWidget>


namespace SDR2DXF {

/*******************************************************************/

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *fbw_leInput;
    QLineEdit *fbw_leOutput;
    QString inputFileName;
    QString outputFileName;

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

public slots:



    void clearSlot()
    {
        inputFileName.clear();
        outputFileName.clear();

        fbw_leInput->clear();
        fbw_leOutput->clear();
    }


};

/*******************************************************************/

} // namespace SDR2DXF

#endif // MAINWINDOW_H
