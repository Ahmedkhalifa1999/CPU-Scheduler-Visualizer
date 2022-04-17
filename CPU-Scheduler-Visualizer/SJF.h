#ifndef SJF_H
#define SJF_H

#include <vector>
#include "GanntChart.h"
#include "process.h"

GanntChart SJF(const std::vector<process>& processes, bool preemptive);


#endif // SJF_H
