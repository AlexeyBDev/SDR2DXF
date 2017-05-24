#include "fileelemen.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

namespace SDR2DXF {

/*******************************************************************/

fileElemen::fileElemen(QWidget *parent)
    : QWidget(parent) {
    // delimiter settings
    int margin = 5;
    int spacing = 5;

    // grid layout
    QGridLayout *GL = new QGridLayout(this);
    GL->setMargin(margin);
    GL->setSpacing(spacing);

    // the block for input file
    QLabel *lblInput = new QLabel(tr("Input file: "));
    leInput = new QLineEdit;
    QPushButton *bInputFile = new QPushButton(tr("Browse source..."));

    // the block for output file
    QLabel *lblOutput = new QLabel(tr("Output file: "));
    leOutput = new QLineEdit;
    QPushButton *bOutputFile = new QPushButton(tr("Browse output..."));

    GL->addWidget(lblInput, 0, 0);
    GL->addWidget(leInput, 0, 1);
    GL->addWidget(bInputFile, 0, 2);
    GL->addWidget(lblOutput, 1, 0);
    GL->addWidget(leOutput, 1, 1);
    GL->addWidget(bOutputFile, 1, 2);

    connect(bInputFile, SIGNAL(clicked(bool)), SLOT(openFileSlot()));
    connect(bOutputFile, SIGNAL(clicked(bool)), SLOT(saveFileSlot()));

}

/*******************************************************************/

fileElemen::~fileElemen() {

}

/*******************************************************************/

void fileElemen::openFileSlot(){
    inputFileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "",
                                                 tr("Sokkia data file (*.sdr)"));
    if(inputFileName != "") {
        leInput->setText(inputFileName);
        outputFileName = inputFileName;
        outputFileName.replace(inputFileName.size() - 3,
                               3,
                               "dxf");
        leOutput->setText(outputFileName);
    }
    else
        inputFileName = leInput->text();
}

/*******************************************************************/

void fileElemen::saveFileSlot()
{
        outputFileName = QFileDialog::getSaveFileName(this, tr("Save output DXF file"),
                                                      "",
                                                      tr("DXF (*.dxf"));
        if(outputFileName != "")
            leOutput->setText(outputFileName);
        else
            outputFileName = leOutput->text();
}

/*******************************************************************/

} // namespace SDR2DXF


