#ifndef METRICS_H
#define METRICS_H

#include "GanntChart.h"
#include "process.h"
#include <vector>

typedef struct{
    float averageTurnAroundTime;
    float maximumTurnAroundTime;
    float averageWaitingTime;
    float maximumWaitingTime;
    float averageResponseTime;
    float maximumResponseTime;
} metrics;

metrics calculateMetrics(GanntChart timeline, const std::vector<process> &processes);

#endif // METRICS_H
