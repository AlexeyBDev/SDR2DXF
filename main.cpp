/*
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication sdr2dxf(argc, argv);
    SDR2DXF::MainWindow mainWin;
    //mainWin.windowTitle("SDR2DXF");
    QSize sizeMainWin(500, 600);
    mainWin.resize(sizeMainWin);
    mainWin.show();

    return sdr2dxf.exec();
}
