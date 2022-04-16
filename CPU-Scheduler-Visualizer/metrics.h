#ifndef METRICS_H
#define METRICS_H

#include "GanntChart.h"

typedef struct{
    float averageTurnAroundTime;
    float maximumTurnAroundTime;
    float averageWaitingTime;
    float maximumWaitingTime;
    float averageResponseTime;
    float maximumResponseTime;
} metrics;

metrics calculateMetrics(GanntChart timeline);

#endif // METRICS_H
