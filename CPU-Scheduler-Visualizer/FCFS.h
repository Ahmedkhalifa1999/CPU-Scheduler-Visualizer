#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "GanntChart.h"

typedef struct {
    unsigned int id; //Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivelTime;
    unsigned int burstLength;
} FCFS_process;

GanntChart FCFS(std::vector<FCFS_process> &processes);

#endif // FCFS_H
