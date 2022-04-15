#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include "GanntChart.h"

typedef struct {
   unsigned int pid;//Process IDs start from 1 (Process ID 0 is reserved)
   unsigned int arrival_time;
    unsigned int burst_time;
  unsigned  int priority;
    unsigned int start_time;
   unsigned int completion_time;
  unsigned  int waiting_time;
} Priority_process;

GanntChart Priority(const std::vector<Priority_process> &processes, bool preemptive);

#endif // PRIORITY_H
