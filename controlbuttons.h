#ifndef CONTROLBUTTONS_H
#define CONTROLBUTTONS_H

#include <QWidget>

namespace SDR2DXF {

/*******************************************************************/

class ControlButtons : public QWidget
{
    Q_OBJECT
public:
    ControlButtons(QWidget *parent = 0);
    virtual ~ControlButtons();

signals:
    void pushClear(void);

public slots:
};

/*******************************************************************/

} // namespace SDR2DXF

#endif // CONTROLBUTTONS_H
