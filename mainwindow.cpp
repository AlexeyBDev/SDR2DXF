#include "mainwindow.h"

//#include <QtWidgets>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QTableView>
#include <QStandardItemModel>

namespace SDR2DXF {

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    // global var
    int margin = 5;
    int spacing = 5;

    // grid layout
    QGridLayout *gridInputData = new QGridLayout;
    gridInputData->setMargin(margin);
    gridInputData->setSpacing(spacing);

    // the block for input file
    QLabel *fbw_lblInput = new QLabel(tr("Input file: "));
    //fbw_lblInput->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    fbw_leInput = new QLineEdit;
    //fbw_leInput->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum));
    QPushButton *fbw_pbInput = new QPushButton(tr("Browse source..."));
    //fbw_pbInput->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed));

    // the block for output file
    QLabel *fbw_lblOutput = new QLabel(tr("Output file: "));
    fbw_leOutput = new QLineEdit;
    QPushButton *fbw_pbOutput = new QPushButton(tr("Browse output..."));

    gridInputData->addWidget(fbw_lblInput, 0, 0);
    gridInputData->addWidget(fbw_leInput, 0, 1);
    gridInputData->addWidget(fbw_pbInput, 0, 2);
    gridInputData->addWidget(fbw_lblOutput, 1, 0);
    gridInputData->addWidget(fbw_leOutput, 1, 1);
    gridInputData->addWidget(fbw_pbOutput, 1, 2);

    // the table view
    QTableView *fbw_Table = new QTableView;
    //QStringList titleList;
    //titleList << tr("Name") << tr("X") << tr("Y") << tr("H") << tr("Code");
    QStandardItemModel model(3, 5);
    fbw_Table->setModel(&model);
    QHBoxLayout *fbw_BoxTable = new QHBoxLayout;
    fbw_BoxTable->setMargin(margin);
    fbw_BoxTable->addWidget(fbw_Table);

    // the command line
    QLabel *fbw_commandLine = new QLabel;
    QHBoxLayout *fbw_BoxCommLine = new QHBoxLayout;
    fbw_BoxCommLine->setMargin(margin);
    fbw_BoxCommLine->addWidget(fbw_commandLine);

    // the group buttons (Settings, Clear, Generate)
    QPushButton *fbw_SettingsB = new QPushButton(tr("Settings"));
    fbw_SettingsB->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));
    QPushButton *fbw_ClearB = new QPushButton(tr("Clear"));
    fbw_ClearB->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));
    QPushButton *fbw_GenerateB = new QPushButton(tr("Generate DXF"));
    fbw_GenerateB->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));
    QHBoxLayout *fbw_GroupB = new QHBoxLayout;
    fbw_GroupB->setAlignment(Qt::AlignLeft);
    fbw_GroupB->setMargin(margin);
    fbw_GroupB->addWidget(fbw_SettingsB);
    fbw_GroupB->addWidget(fbw_ClearB);
    fbw_GroupB->addWidget(fbw_GenerateB);

    // the common block
    QVBoxLayout *fbw_CommonBlock = new QVBoxLayout(this);
    fbw_CommonBlock->addLayout(gridInputData);
    fbw_CommonBlock->addLayout(fbw_BoxTable);
    //fbw_CommonBlock->addLayout(fbw_BoxCommLine);
    fbw_CommonBlock->addLayout(fbw_GroupB);
    fbw_CommonBlock->setMargin(margin);

    connect(fbw_pbInput, SIGNAL(clicked(bool)), SLOT(openFileSlot()));
    connect(fbw_pbOutput, SIGNAL(clicked(bool)), SLOT(saveFileSlot()));
    connect(fbw_ClearB, SIGNAL(clicked(bool)), SLOT(clearSlot()));

}

MainWindow::~MainWindow()
{
}



} // namespace SDR2DXF
