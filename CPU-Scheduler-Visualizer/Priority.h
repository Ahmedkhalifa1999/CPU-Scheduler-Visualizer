#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include "GanntChart.h"

typedef struct {
    int pid;//Process IDs start from 1 (Process ID 0 is reserved)
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
} Priority_process;

GanntChart Priority(const std::vector<Priority_process> &processes, bool preemptive);

#endif // PRIORITY_H
