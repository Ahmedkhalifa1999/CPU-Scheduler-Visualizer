#ifndef PROCESSES_H
#define PROCESSES_H
#include <vector>
typedef struct {
    int pid;  /*from1*/
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
}processes;
typedef std::vector<processes> process;

//typedef std::vector<processes> process;
#endif // PROCESSES_H

