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

    if (preemptive) {
        while (std::accumulate(remainingTime.begin(), remainingTime.end(), 0) != 0) {
            unsigned int currentProcessIndex = nextProcessIndex;
            unsigned int finishTime = currentTime + remainingTime[currentProcessIndex];
            unsigned int shortestJobTime = UINT_MAX;
            for (unsigned int i = 0; i < processCount; i++) {
                if (i != currentProcessIndex && processes[currentProcessIndex].arrivalTime <= finishTime && remainingTime[i] < shortestJobTime && remainingTime[i] > 0) {
                    nextProcessIndex = i;
                    shortestJobTime = remainingTime[i];
                }
            }
            section.end = finishTime;
            remainingTime[currentProcessIndex] = 0;
            chart.push_back(section);
            if (currentProcessIndex == nextProcessIndex) {
                firstArrivalTime = UINT_MAX;
                //Get earliest process to arrive (ties resolved on burst length)
                for (unsigned int i = 0; i < processCount; i++) {
                    if (processes[i].arrivalTime <= firstArrivalTime && remainingTime[i] > 0) {
                        if (processes[i].arrivalTime == firstArrivalTime) {
                            if (remainingTime[i] < remainingTime[firstArrivalIndex]) {
                                firstArrivalIndex = i;
                                firstArrivalTime = processes[i].arrivalTime;
                            }
                        }
                        else {
                            firstArrivalIndex = i;
                            firstArrivalTime = processes[i].arrivalTime;
                        }
                    }
                }
                if (firstArrivalTime != UINT_MAX) {
                    section.start = 0;
                    section.end = firstArrivalTime;
                    section.process = 0;
                    chart.push_back(section);
                }
                currentTime = firstArrivalTime;
                section.start = firstArrivalTime;
                section.process = processes[firstArrivalIndex].id;
                nextProcessIndex = firstArrivalIndex;
            }
       }
        }
    else {
        while (std::accumulate(remainingTime.begin(), remainingTime.end(), 0) != 0) {
             unsigned int currentProcessIndex = nextProcessIndex;
             unsigned int finishTime = currentTime + remainingTime[currentProcessIndex];
             unsigned int shortestJobTime = UINT_MAX;
             for (unsigned int i = 0; i < processCount; i++) {
                 if (i != currentProcessIndex && processes[currentProcessIndex].arrivalTime <= finishTime && remainingTime[i] < shortestJobTime && remainingTime[i] > 0) {
                     nextProcessIndex = i;
                     shortestJobTime = remainingTime[i];
                 }
             }
             section.end = finishTime;
             remainingTime[currentProcessIndex] = 0;
             chart.push_back(section);
             if (currentProcessIndex == nextProcessIndex) {
                 firstArrivalTime = UINT_MAX;
                 //Get earliest process to arrive (ties resolved on burst length)
                 for (unsigned int i = 0; i < processCount; i++) {
                     if (processes[i].arrivalTime <= firstArrivalTime && remainingTime[i] > 0) {
                         if (processes[i].arrivalTime == firstArrivalTime) {
                             if (remainingTime[i] < remainingTime[firstArrivalIndex]) {
                                 firstArrivalIndex = i;
                                 firstArrivalTime = processes[i].arrivalTime;
                             }
                         }
                         else {
                             firstArrivalIndex = i;
                             firstArrivalTime = processes[i].arrivalTime;
                         }
                     }
                 }
                 if (firstArrivalTime != UINT_MAX) {
                     section.start = 0;
                     section.end = firstArrivalTime;
                     section.process = 0;
                     chart.push_back(section);
                 }
                 currentTime = firstArrivalTime;
                 section.start = firstArrivalTime;
                 section.process = processes[firstArrivalIndex].id;
                 nextProcessIndex = firstArrivalIndex;
             }
        }
    }

    return chart;
}
