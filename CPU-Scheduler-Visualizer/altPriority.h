#ifndef ALTPRIORITY_H
#define ALTPRIORITY_H

#include <vector>
#include "GanntChart.h"
#include "process.h"

GanntChart altPriority(const std::vector<process> &processes, bool preemptive);


#endif // ALTPRIORITY_H
