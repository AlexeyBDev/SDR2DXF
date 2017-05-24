#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QFileDialog>
#include <QWidget>


namespace SDR2DXF {

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

    void openFileSlot()
    {
        inputFileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                          "",
                                                          tr("Sokkia data file (*.sdr)"));
        if(inputFileName != "") {
            fbw_leInput->setText(inputFileName);
            outputFileName = inputFileName;
            outputFileName.replace(inputFileName.size() - 3,
                                   3,
                                   "dxf");
            fbw_leOutput->setText(outputFileName);
        }
        else
            inputFileName = fbw_leInput->text();
    }

    void saveFileSlot()
    {
        outputFileName = QFileDialog::getSaveFileName(this, tr("Save output DXF file"),
                                                      "",
                                                      tr("DXF (*.dxf"));
        if(outputFileName != "")
            fbw_leOutput->setText(outputFileName);
        else
            outputFileName = fbw_leOutput->text();
    }

    void clearSlot()
    {
        inputFileName.clear();
        outputFileName.clear();

        fbw_leInput->clear();
        fbw_leOutput->clear();
    }


};


} // namespace SDR2DXF

#endif // MAINWINDOW_H
