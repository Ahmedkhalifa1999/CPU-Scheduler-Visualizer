#include "Priority.h"
#include <iostream>
#include <map>
using namespace std;

GanntChart Priority(const std::vector<process>& p, bool preemptive) {
    GanntChart gc;
    GanntChartSection gcs;
    map<int, int> stime;
    unsigned int n = p.size();
    vector<unsigned int> burst_remaining(n);
    vector<bool> is_completed(n, false);
    vector<unsigned int> start_time(n);
    vector<unsigned int> completion_time(n);
    unsigned int current_time = 0;
    unsigned int completed = 0;
    for (unsigned int i = 0; i < n; i++) {
        burst_remaining[i] = p[i].burstLength;
    }
    if (preemptive) {
        while (completed != n) {
            int idx = -1;
            unsigned int mx = 0;
            for (unsigned int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == false) {
                    if (p[i].priority > mx) {
                        mx = p[i].priority;
                        idx = i;
                    }
                    if (p[i].priority == mx) {
                        if (p[i].arrivalTime < p[idx].arrivalTime) {
                            mx = p[i].priority;
                            idx = i;
                        }
                    }
                }
            }

            if (idx != -1) {
                if (burst_remaining[idx] == p[idx].burstLength) {
                    start_time[idx] = current_time;

                }
                burst_remaining[idx] -= 1;
                current_time++;

                if (burst_remaining[idx] == 0) {
                    completion_time[idx] = current_time;
                    is_completed[idx] = true;
                    completed++;
                }
            }
            else {
                current_time++;
            }
        }
    }

    else {
        while (completed != n) {
            int idx = -1;
            unsigned int mx = 0;
            for (unsigned int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == false) {
                    if (p[i].priority > mx) {
                        mx = p[i].priority;
                        idx = i;
                    }
                    if (p[i].priority == mx) {
                        if (p[i].arrivalTime < p[idx].arrivalTime) {
                            mx = p[i].priority;
                            idx = i;
                        }
                    }
                }
            }
            if (idx != -1) {
                start_time[idx] = current_time;
                completion_time[idx] = start_time[idx] + p[idx].burstLength;
                is_completed[idx] = true;
                completed++;
                current_time = completion_time[idx];
            }
            else {
                current_time++;
            }

        }
    }
    for (unsigned int i = 0; i < n; i++) {
        stime.insert({ start_time[i],p[i].id, });
    }

    for (unsigned int i = 0; i < n; i++) {
        gcs.process = stime.begin()->second;  gcs.start = stime.begin()->first; gcs.end = completion_time[stime.begin()->second];
        stime.erase(stime.begin()->first);
        gc.push_back(gcs);
    }

    return gc;
}
