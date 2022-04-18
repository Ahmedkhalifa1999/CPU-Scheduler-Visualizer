#include "SJF.h"
#include <limits>
using namespace std;

GanntChart SJF(const vector<process>& p, bool preemptive) {

    GanntChart gc;
    GanntChartSection gcs;
    unsigned int n = p.size();
    vector<unsigned int> startTime(n);
    vector<unsigned int> completionTime(n);
    vector<unsigned int> burst_remaining(n);
    vector<bool> is_completed(n, false);

    unsigned int current_time = 0;
    unsigned int completed = 0;
    unsigned int prev = 0;
    if (!preemptive) {

        while (completed != n) {
            int idx = -1;
            unsigned int mn = numeric_limits<unsigned int>::max();
            for (unsigned int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == 0) {
                    if (p[i].burstLength < mn) {
                        mn = p[i].burstLength;
                        idx = i;
                    }
                    if (p[i].burstLength == mn) {
                        if (p[i].arrivalTime < p[idx].arrivalTime) {
                            mn = p[i].burstLength;
                            idx = i;
                        }
                    }
                }
            }
            if (idx != -1) {
                startTime[idx] = current_time;
                completionTime[idx] = startTime[idx] + p[idx].burstLength;
                is_completed[idx] = 1;
                completed++;
                current_time = completionTime[idx];
                gcs.process = p[idx].id;
                gcs.start = startTime[idx];
                gcs.end = completionTime[idx];
                gc.push_back(gcs);
            }
            else {
                current_time++;
            }
        }
    }
    else {
        for (unsigned int i = 0; i < n; i++) {
            burst_remaining[i] = p[i].burstLength;
        }
        while (completed != n) {
            int idx = -1;
            unsigned int mn = numeric_limits<unsigned int>::max();
            for (unsigned int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == 0) {
                    if (burst_remaining[i] < mn) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                    if (burst_remaining[i] == mn) {
                        if (p[i].arrivalTime < p[idx].arrivalTime) {
                            mn = burst_remaining[i];
                            idx = i;
                        }
                    }
                }
            }

            if (idx != -1) {
                if (burst_remaining[idx] == p[idx].burstLength) {
                    startTime[idx] = current_time;
                   

                }
                burst_remaining[idx] -= 1;
                current_time++;
                prev = current_time;
                /*gcs.end = prev;
                gc.push_back(gcs);*/

                if (burst_remaining[idx] == 0) {
                    completionTime[idx] = current_time;
                    gcs.process = p[idx].id;
                    gcs.start = startTime[idx];
                    gcs.end = completionTime[idx];
                    gc.push_back(gcs);
                    is_completed[idx] = 1;
                    completed++; 
                }
            }
            else {
                current_time++;
            }
        }
    }

    /*for (unsigned int i = 0; i < n; i++) {
        gcs.process = p[i].id;
        gcs.start = startTime[i];
        gcs.end = completionTime[i];
        gc.push_back(gcs);
    }*/


    return gc;

}

