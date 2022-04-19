#include "altSJF.h"
#include <numeric> //for accumulate function
#include <limits.h>

GanntChart altSJF(const std::vector<process>& processes, bool preemptive) {
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
    unsigned int nextProcessRemainingTime = processes[firstArrivalIndex].priority;
    unsigned int nextProcessArrivalTime = firstArrivalTime;

    while (std::accumulate(remainingTime.begin(), remainingTime.end(), 0) != 0) {
         unsigned int currentProcessIndex = nextProcessIndex;
         unsigned int currentProcessRemainingTime = nextProcessRemainingTime;
         //unsigned int currentProcessArrivaltime = nextProcessArrivalTime;
         nextProcessRemainingTime = UINT_MAX;
         unsigned int finishTime = currentTime + remainingTime[currentProcessIndex];
         for (unsigned int i = 0; i < processCount; i++) {
             if (i != currentProcessIndex //Process is not current process
              && processes[i].arrivalTime <= finishTime //Process will arrive before next process finished
              && remainingTime[i] > 0 //Process still needs CPU time
              && remainingTime[i] <= nextProcessRemainingTime) //Process has the highest priority of all valid
             {
                 nextProcessIndex = i;
                 nextProcessRemainingTime =remainingTime[i];
                 nextProcessArrivalTime = processes[i].arrivalTime;
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
             nextProcessRemainingTime = remainingTime[nextProcessIndex];
             nextProcessArrivalTime = processes[nextProcessIndex].arrivalTime;
             section.end = nextProcessArrivalTime;
             chart.push_back(section);
             section.start = section.end;
             section.process = processes[nextProcessIndex].id;
             currentTime = section.start;
         }
         else {
             if (preemptive && nextProcessRemainingTime > currentProcessRemainingTime) { //if next process has more remaining time than current, goes to else (same as nonpreemptive)
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
