#include "chartarea.h"
#include <QPainter>
#include <QFontMetrics>

ChartArea::ChartArea(QWidget *parent)
    : QWidget{parent}
{

}

void ChartArea::paintEvent(QPaintEvent* event){
    unsigned int start = 10;
    unsigned int chartLength = this->width() - 20;
    unsigned int height = this->height()-30;
    unsigned int totalTime = 0;
    QPainter painter(this);  
    QFontMetrics fontRuler = painter.fontMetrics();
    for (GanntChartSection section: this->timeline) {
        totalTime += section.end - section.start;
    }
    if (totalTime == 0) return;
    QString startTimeText = QString::number(0);
    int startTimeTextWidth = fontRuler.horizontalAdvance(startTimeText);
    painter.drawText(start - startTimeTextWidth/2, height+21, startTimeText);
    for (GanntChartSection section: this->timeline) {
        int width = ((section.end - section.start)*chartLength) / totalTime;
        painter.drawRect(start, 10, width, height);
        painter.fillRect(start+1, 11, width-1, height-1, QBrush(Qt::white));
        QString processText = "P" + QString::number(section.process);
        int processTextWidth = fontRuler.horizontalAdvance(processText);
        painter.drawText(start + (width/2) - (processTextWidth/2), (height-10)/2, processText);
        start += width;
        QString timeText = QString::number(section.end);
        int timeTextWidth = fontRuler.horizontalAdvance(timeText);
        painter.drawText(start - timeTextWidth/2, height+21, timeText);
    }
}
