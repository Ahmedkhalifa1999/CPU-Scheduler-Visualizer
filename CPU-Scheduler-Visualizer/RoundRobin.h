#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <vector>
#include "GanntChart.h"

typedef struct {
    unsigned int id; //Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivalTime;
    signed int burstLength;
} RoundRobin_process;

GanntChart RoundRobin(const std::vector<RoundRobin_process> &processes, unsigned int timeQuantum);

#endif // ROUNDROBIN_H
