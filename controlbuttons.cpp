#include "controlbuttons.h"

#include <QPushButton>
#include <QHBoxLayout>

namespace SDR2DXF {

/*******************************************************************/

ControlButtons::ControlButtons(QWidget *parent)
    : QWidget(parent)
{
    // global var
    int margin = 5;

    // the group buttons (Settings, Clear, Generate)
    QPushButton *eettingsBut = new QPushButton(tr("Settings"));
    eettingsBut->setSizePolicy(QSizePolicy(QSizePolicy::Maximum,
                                             QSizePolicy::Maximum));

    QPushButton *clearBut = new QPushButton(tr("Clear"));
    clearBut->setSizePolicy(QSizePolicy(QSizePolicy::Maximum,
                                          QSizePolicy::Maximum));

    QPushButton *generateBut = new QPushButton(tr("Generate DXF"));
    generateBut->setSizePolicy(QSizePolicy(QSizePolicy::Maximum,
                                             QSizePolicy::Maximum));
    QHBoxLayout *groupBut = new QHBoxLayout(this);

    groupBut->setAlignment(Qt::AlignLeft);
    groupBut->setMargin(margin);

    groupBut->addWidget(eettingsBut);
    groupBut->addWidget(clearBut);
    groupBut->addWidget(generateBut);

    connect(clearBut, SIGNAL(clicked(bool)), this, SIGNAL(pushClear()));

}

/*******************************************************************/

ControlButtons::~ControlButtons() {

}

/*******************************************************************/

} // namespace SDR2DXF
