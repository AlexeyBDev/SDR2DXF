#include "mainwindow.h"
#include "fileelemen.h"
#include "table.h"
#include "controlbuttons.h"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QTableView>
#include <QStandardItemModel>

namespace SDR2DXF {

/*******************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    // global var
    int margin = 5;
//    int spacing = 5;

    fileElemen *Fe = new fileElemen(this);

    Table *Tab = new Table(this);

    // the command line
//    QLabel *fbw_commandLine = new QLabel;
//    QHBoxLayout *fbw_BoxCommLine = new QHBoxLayout;
//    fbw_BoxCommLine->setMargin(margin);
//    fbw_BoxCommLine->addWidget(fbw_commandLine);

    ControlButtons *Bts = new ControlButtons(this);

    // the common block
    QVBoxLayout *genLeyout = new QVBoxLayout(this);
    genLeyout->addWidget(Fe);
    genLeyout->addWidget(Tab);
    genLeyout->addWidget(Bts);

    genLeyout->setMargin(margin);

    connect(Bts, SIGNAL(pushClear()), Fe, SLOT(clearInputLineEdit()));
    connect(Bts, SIGNAL(pushClear()), Fe, SLOT(clearOutputLineEdit()));
    connect(Bts, SIGNAL(pushClear()), Tab, SLOT(clearTable()));
//    connect(fbw_pbOutput, SIGNAL(clicked(bool)), SLOT(saveFileSlot()));
//    connect(fbw_ClearB, SIGNAL(clicked(bool)), SLOT(clearSlot()));

}

MainWindow::~MainWindow() {

}



} // namespace SDR2DXF
