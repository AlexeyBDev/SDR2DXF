#include "mainwindow.h"
#include "fileelemen.h"

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

    fileElemen *FE = new fileElemen(this);


    // the table view
    QTableView *fbw_Table = new QTableView;
    //QStringList titleList;
    //titleList << tr("Name") << tr("X") << tr("Y") << tr("H") << tr("Code");
//    QStandardItemModel model(3, 5);
//    fbw_Table->setModel(&model);

    QHBoxLayout *fbw_BoxTable = new QHBoxLayout;
    fbw_BoxTable->setMargin(margin);
    fbw_BoxTable->addWidget(fbw_Table);

    // the command line
    QLabel *fbw_commandLine = new QLabel;
    QHBoxLayout *fbw_BoxCommLine = new QHBoxLayout;
    fbw_BoxCommLine->setMargin(margin);
    fbw_BoxCommLine->addWidget(fbw_commandLine);

    ControlButtons *Bts = new ControlButtons(this);

    // the common block
    QVBoxLayout *fbw_CommonBlock = new QVBoxLayout(this);
    //fbw_CommonBlock->addLayout(gridInputData);
    fbw_CommonBlock->addWidget(FE);
    fbw_CommonBlock->addLayout(fbw_BoxTable);
    //fbw_CommonBlock->addLayout(fbw_BoxCommLine);
    fbw_CommonBlock->addWidget(Bts);
    fbw_CommonBlock->setMargin(margin);

    connect(Bts, SIGNAL(pushClear()), FE, SLOT(clearInputLineEdit()));
    connect(Bts, SIGNAL(pushClear()), FE, SLOT(clearOutputLineEdit()));
//    connect(fbw_pbOutput, SIGNAL(clicked(bool)), SLOT(saveFileSlot()));
//    connect(fbw_ClearB, SIGNAL(clicked(bool)), SLOT(clearSlot()));

}

MainWindow::~MainWindow()
{
}



} // namespace SDR2DXF
