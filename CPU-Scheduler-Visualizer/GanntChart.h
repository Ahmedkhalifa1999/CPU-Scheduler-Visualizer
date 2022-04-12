#ifndef GANNTCHART_H
#define GANNTCHART_H

#include <vector>

typedef struct {
    unsigned int process; //Process IDs start from 1 (Process ID 0 indicated idle section)
    unsigned int start;
    unsigned int end;
} GanntChartSection;

typedef std::vector<GanntChartSection> GanntChart; //GanntChart is a vector of GanntChartSections


#endif // GANNTCHART_H
