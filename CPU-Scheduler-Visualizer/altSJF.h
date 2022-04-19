#ifndef ALTSJF_H
#define ALTSJF_H

#include <vector>
#include "GanntChart.h"
#include "process.h"

GanntChart altSJF(const std::vector<process>& processes, bool preemptive);

#endif // ALTSJF_H
