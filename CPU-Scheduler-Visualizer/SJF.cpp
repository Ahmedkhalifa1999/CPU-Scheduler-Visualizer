#include "SJF.h"
using namespace std;

GanntChart SJF(const vector<process>& p, bool preemptive) {

    GanntChart gc;
    GanntChartSection gcs;
    int n = p.size();
    vector<int> startTime(n);
    vector<int> completionTime(n);
    vector <int> burst_remaining(n);
    vector <int> is_completed(100, 0);

    int current_time = 0;
    int completed = 0;
    int prev = 0;
    if (!preemptive) {

        while (completed != n) {
            int i, idx = -1;
            int mn = 10000000;
            for (i = 0; i < n; i++) {
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
                prev = current_time;
            }
            else {
                current_time++;
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            burst_remaining[i] = p[i].burstLength;
        }
        while (completed != n) {
            int idx = -1;
            int mn = 10000000;
            for (int i = 0; i < n; i++) {
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

                if (burst_remaining[idx] == 0) {
                    completionTime[idx] = current_time;

                    is_completed[idx] = 1;
                    completed++;
                }
            }
            else {
                current_time++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        gcs.process = p[i].id; gcs.start = startTime[i]; gcs.end = completionTime[i];
        gc.push_back(gcs);
    }


    return gc;

}

