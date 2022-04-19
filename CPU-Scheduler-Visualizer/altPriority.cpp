#include "altPriority.h"
#include <numeric> //for accumulate function
#include <limits.h>

GanntChart altPriority(const std::vector<process> &processes, bool preemptive) {
    unsigned int processCount = processes.size();
    unsigned int currentTime = 0; //holds current simulation time
    std::vector<unsigned int> remainingTime(processCount); //holds remaining time for each process (match on vector index)
    GanntChart chart; //Output

    //Initializing remainingTime
    for (unsigned int i = 0; i < processCount; i++) {
        remainingTime[i] = processes[i].burstLength;
    }

    //Initialization for main loop
    GanntChartSection section;
    unsigned int firstArrivalIndex = 0;
    unsigned int firstArrivalTime = processes[firstArrivalIndex].arrivalTime;
    for (unsigned int i = 1; i < processCount; i++) {
        if (processes[i].arrivalTime < firstArrivalTime) {
            firstArrivalIndex = i;
            firstArrivalTime = processes[i].arrivalTime;
        }
    }
    if (firstArrivalTime > 0) { //In case first process is idle
        section.start = 0;
        section.end = firstArrivalTime;
        section.process = 0;
        chart.push_back(section);
    }
    currentTime = firstArrivalTime;
    section.start = firstArrivalTime;
    section.process = processes[firstArrivalIndex].id;
    unsigned int nextProcessIndex = firstArrivalIndex;
    unsigned int nextProcessPriority = processes[firstArrivalIndex].priority;
    unsigned int nextProcessArrivalTime = firstArrivalTime;

    while (std::accumulate(remainingTime.begin(), remainingTime.end(), 0) != 0) {
         unsigned int currentProcessIndex = nextProcessIndex;
         unsigned int currentProcessPriority = nextProcessPriority;
         //unsigned int currentProcessArrivaltime = nextProcessArrivalTime;
         nextProcessPriority = 0;
         unsigned int finishTime = currentTime + remainingTime[currentProcessIndex];
         if (preemptive) {
             for (unsigned int i = 0; i < processCount; i++) {
                 if (i != currentProcessIndex //Process is not current process
                  && processes[i].arrivalTime <= finishTime //Process will arrive before next process finished
                  && remainingTime[i] > 0 //Process still needs CPU time
                  && processes[i].priority > currentProcessPriority //Process has higher priority than current
                  && processes[i].arrivalTime >= processes[nextProcessIndex].arrivalTime) //Process is the earlieast to arrive
                 {
                     nextProcessIndex = i;
                     nextProcessPriority = processes[i].priority;
                     nextProcessArrivalTime = processes[i].arrivalTime;
                 }
             }
         }
         else {
             for (unsigned int i = 0; i < processCount; i++) {
                 if (i != currentProcessIndex //Process is not current process
                  && processes[i].arrivalTime <= finishTime //Process will arrive before next process finished
                  && remainingTime[i] > 0 //Process still needs CPU time
                  && processes[i].priority > nextProcessPriority) //Process has the highest priority of all valid
                 {
                     nextProcessIndex = i;
                     nextProcessPriority = processes[i].priority;
                     nextProcessArrivalTime = processes[i].arrivalTime;
                 }
             }
         }
         if (currentProcessIndex == nextProcessIndex) { //Idle process needed or last process
             section.end = finishTime;
             chart.push_back(section);
             remainingTime[currentProcessIndex] = 0;
             //Search for first arrival after idle
             firstArrivalIndex = 0;
             firstArrivalTime = UINT_MAX;
             for (unsigned int i = 0; i < processCount; i++) {
                 if (processes[i].arrivalTime < firstArrivalTime && i != currentProcessIndex && remainingTime[i] > 0) {
                     firstArrivalIndex = i;
                     firstArrivalTime = processes[i].arrivalTime;
                 }
             }
             if (firstArrivalTime == UINT_MAX) continue; //last process
             section.start = section.end;
             section.process = 0;
             nextProcessIndex = firstArrivalIndex;
             nextProcessPriority = processes[nextProcessIndex].priority;
             nextProcessArrivalTime = processes[nextProcessIndex].arrivalTime;
             section.end = nextProcessArrivalTime;
             chart.push_back(section);
             section.start = section.end;
             section.process = processes[nextProcessIndex].id;
             currentTime = section.start;
         }
         else {
             if (preemptive && nextProcessPriority > currentProcessPriority) { //if next process has lower priority than current, goes to else (same as nonpreemptive)
                section.end = nextProcessArrivalTime;
                chart.push_back(section);
                remainingTime[currentProcessIndex] -= (section.end - section.start);
                section.start = section.end;
                section.process = processes[nextProcessIndex].id;
                currentTime = section.start;
             }
             else {
                 section.end = finishTime;
                 chart.push_back(section);
                 remainingTime[currentProcessIndex] = 0;
                 section.start = section.end;
                 section.process = processes[nextProcessIndex].id;
                 currentTime = section.start;
             }
         }
    }

    return chart;
}
