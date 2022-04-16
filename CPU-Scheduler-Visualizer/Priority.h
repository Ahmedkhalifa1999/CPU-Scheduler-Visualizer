#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include "GanntChart.h"

typedef struct {
    unsigned int id;//Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivalTime;
    unsigned int burstLength;
    unsigned int priority;
} Priority_process;

GanntChart Priority(const std::vector<Priority_process> &processes, bool preemptive);

#endif // PRIORITY_H
