#ifndef GANNTCHART_H
#define GANNTCHART_H

#include <list>

typedef struct {
    unsigned int process; //Process IDs start from 1 (Process ID 0 indicated idle section)
    unsigned int start;
    unsigned int end;
} GanntChartSection;

typedef std::list<GanntChartSection> GanntChart; //GanntChart is a vector of GanntChartSections


#endif // GANNTCHART_H
