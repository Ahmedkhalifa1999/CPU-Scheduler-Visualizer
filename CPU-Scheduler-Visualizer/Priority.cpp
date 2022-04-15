#include "Priority.h"
#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
using namespace std;

GanntChart Priority(const std::vector<Priority_process> &p,bool preemptive) {
  //preemtive 
    GanntChart gc(100,1);
        int n;

        float avg_waiting_time;
        int total_waiting_time = 0;
        int burst_remaining[100];
        int is_completed[100];
        memset(is_completed, 0, sizeof(is_completed));

        cout << setprecision(2) << fixed;
        int current_time = 0;
        int completed = 0;
        int prev = 0;

        while (completed != n) {
            int idx = -1;
            int mx = -1;
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= current_time && is_completed[i] == 0) {
                    if (p[i].priority > mx) {
                        mx = p[i].priority;
                        idx = i;
                    }
                    if (p[i].priority == mx) {
                        if (p[i].arrival_time < p[idx].arrival_time) {
                            mx = p[i].priority;
                            idx = i;
                        }
                    }
                }
            }

            if (idx != -1) {
                if (burst_remaining[idx] == p[idx].burst_time) {
                    p[idx].start_time = current_time;
                }
                burst_remaining[idx] -= 1;
                current_time++;
                prev = current_time;

                if (burst_remaining[idx] == 0) {
                    p[idx].completion_time = current_time;
                    p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                    p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                    p[idx].response_time = p[idx].start_time - p[idx].arrival_time;
                    total_waiting_time += p[idx].waiting_time;

                    is_completed[idx] = 1;
                    completed++;
                }
            }
            else {
                current_time++;
            }
        }

        int min_arrival_time = 10000000;
        int max_completion_time = -1;
        for (int i = 0; i < n; i++) {
            min_arrival_time = min(min_arrival_time, p[i].arrival_time);
            max_completion_time = max(max_completion_time, p[i].completion_time);
        }

        avg_waiting_time = (float)total_waiting_time / n;

        for (int i = 0; i < n; i++) {
            gc[i].process = p[i].pid;  gc[i].start = p[i].start_time;  gc[i].end = p[i].completion_time;
            
        }
        cout << "Average Waiting Time = " << avg_waiting_time << endl;

        return gc;
    }
GanntChart Priority(const std::vector<Priority_process>& p,bool preemptive){
    //non preemptive  
    GanntChart gc(100,0);
        int n;
        float avg_waiting_time;
        int total_waiting_time = 0;
        int is_completed[100];
        memset(is_completed, 0, sizeof(is_completed));

        cout << setprecision(2) << fixed;
        int current_time = 0;
        int completed = 0;
        int prev = 0;

        while (completed != n) {
            int idx = -1;
            int mx = -1;
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= current_time && is_completed[i] == 0) {
                    if (p[i].priority > mx) {
                        mx = p[i].priority;
                        idx = i;
                    }
                    if (p[i].priority == mx) {
                        if (p[i].arrival_time < p[idx].arrival_time) {
                            mx = p[i].priority;
                            idx = i;
                        }
                    }
                }
            }
            if (idx != -1) {
                p[idx].start_time = current_time;
                p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                p[idx].response_time = p[idx].start_time - p[idx].arrival_time;

                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;
                completed++;
                current_time = p[idx].completion_time;
                prev = current_time;
            }
            else {
                current_time++;
            }

        }

        int min_arrival_time = 10000000;
        int max_completion_time = -1;
        for (int i = 0; i < n; i++) {
            min_arrival_time = min(min_arrival_time, p[i].arrival_time);
            max_completion_time = max(max_completion_time, p[i].completion_time);
        }

        avg_waiting_time = (float)total_waiting_time / n;

        for (int i = 0; i < n; i++) {
            gc[i].process = p[i].pid;  gc[i].start = p[i].start_time;  gc[i].end = p[i].completion_time;

        }
        cout << "Average Waiting Time = " << avg_waiting_time << endl;
        return gc;
    }


