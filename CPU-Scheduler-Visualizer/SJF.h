#ifndef SJF_H
#define SJF_H

#include <vector>
#include "GanntChart.h"
#include "processes.h"

typedef struct {
    unsigned int id; //Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivelTime;
    unsigned int burstLength;
} SJF_process;

GanntChart SJFN();
GanntChart SJFP();

#endif // SJF_H
