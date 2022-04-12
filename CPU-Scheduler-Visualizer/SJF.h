#ifndef SJF_H
#define SJF_H

#include <vector>
#include "GanntChart.h"

typedef struct {
    unsigned int id; //Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivelTime;
    unsigned int burstLength;
} SJF_process;

GanntChart SJF(const std::vector<SJF_process> &processes, bool preemptive);

#endif // SJF_H
