#ifndef CHARTAREA_H
#define CHARTAREA_H

#include <QWidget>
#include "GanntChart.h"
#include "process.h"

class ChartArea : public QWidget
{
    Q_OBJECT
public:
    explicit ChartArea(QWidget *parent = nullptr);
    GanntChart timeline;

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // CHARTAREA_H
