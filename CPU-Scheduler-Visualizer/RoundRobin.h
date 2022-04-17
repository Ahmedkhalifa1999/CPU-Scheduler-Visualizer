#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <vector>
#include "GanntChart.h"
#include "process.h"

GanntChart RoundRobin(const std::vector<process> &processes, unsigned int timeQuantum);

#endif // ROUNDROBIN_H
