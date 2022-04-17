#include "Priority.h"
#include <iostream>
using namespace std;

GanntChart Priority(const std::vector<Priority_process>& p, bool preemptive) {
    GanntChart gc;
    GanntChartSection gcs;
    int n = p.size();
    float avg_waiting_time;
    int total_waiting_time = 0;
    int burst_remaining[100];
    vector< int> is_completed(100, 0);
    vector < int> start_time;
    vector<int> completion_time;
    vector <int> waiting_time;
    vector<int> turnaround_time;
    vector< int> response_time;
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        burst_remaining[i] = p[i].burstLength;
    }
    if (preemptive == true) {
        while (completed != n) {
            int idx = -1;
            int mx = -1;
            for (int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == 0) {
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
                prev = current_time;

                if (burst_remaining[idx] == 0) {
                    completion_time[idx] = current_time;
                    turnaround_time[idx] = completion_time[idx] - p[idx].arrivalTime;
                    waiting_time[idx] = turnaround_time[idx] - p[idx].burstLength;
                    response_time[idx] = start_time[idx] - p[idx].arrivalTime;
                    total_waiting_time += waiting_time[idx];

                    is_completed[idx] = 1;
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
            int mx = -1;
            for (int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == 0) {
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
                turnaround_time[idx] = completion_time[idx] - p[idx].arrivalTime;
                waiting_time[idx] = turnaround_time[idx] - p[idx].burstLength;
                response_time[idx] = start_time[idx] - p[idx].arrivalTime;

                total_waiting_time += waiting_time[idx];
                is_completed[idx] = 1;
                completed++;
                current_time = completion_time[idx];
                prev = current_time;
            }
            else {
                current_time++;
            }

        }
    }
    for (int i = 0; i < n; i++) {
        gcs.process = p[i].id;  gcs.start = start_time[i];  gcs.end = completion_time[i];
        gc.push_back(gcs);
    }

    return gc;
}
