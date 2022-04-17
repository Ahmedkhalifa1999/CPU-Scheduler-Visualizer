#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include "GanntChart.h"
#include "process.h"

GanntChart Priority(const std::vector<process> &processes, bool preemptive);

#endif // PRIORITY_H
