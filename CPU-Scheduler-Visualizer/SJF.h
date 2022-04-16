#ifndef SJF_H
#define SJF_H

#include <vector>
#include "GanntChart.h"

typedef struct {
    unsigned int id; //Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivelTime;
    unsigned int burstLength;
} SJF_process;

GanntChart SJFN(const std::vector<SJF_process> &processes);
<<<<<<< HEAD
GanntChart SJFP(const std::vector<SJF_process>& processes);
=======
GanntChart SJFP(const std::vector<SJF_process> &processes);
>>>>>>> parent of 95eca4e (SJF)

#endif // SJF_H
