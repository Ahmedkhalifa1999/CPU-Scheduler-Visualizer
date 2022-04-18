#include "Priority.h"
#include <iostream>
using namespace std;

GanntChart Priority(const std::vector<process>& p, bool preemptive) {
    GanntChart gc;
    unsigned int n = p.size();
    vector<unsigned int> burst_remaining(n);
    vector<bool> is_completed(n, false);
    vector<unsigned int> start_time(n);
    vector<unsigned int> completion_time(n);
    unsigned int current_time = 0;
    unsigned int completed = 0;
    int temp = -1;
    for (unsigned int i = 0; i < n; i++) {
        burst_remaining[i] = p[i].burstLength;
    }
    if (preemptive) {
        while (completed != n) {
            int idx = -1;
            int prev = -1;
            unsigned int mx = 0;
            for (unsigned int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == false) {
                    if (p[i].priority > mx) {
                        prev = idx; //index of the previous highest process
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
                    if (prev != -1 && burst_remaining[prev] != 0 && p[idx].priority > p[prev].priority) {
                        if (temp != idx) {
                            gc.push_back({ p[prev].id,start_time[prev],p[idx].arrivalTime });
                            temp = idx;
                        }
                    }//lama ykoon lesa awel mara yeshtghal
                }
                else {
                    if (prev != -1 && burst_remaining[prev] != 0 && p[idx].priority > p[prev].priority) {
                        if (temp != idx) {
                            gc.push_back({ p[prev].id,current_time,p[idx].arrivalTime });//eshtghal abl kedaa
                            temp = idx;
                        }
                    }
                }

                burst_remaining[idx] -= 1;
                current_time++;


                if (burst_remaining[idx] == 0) {
                    completion_time[idx] = current_time;
                    if (start_time[idx] == completion_time[idx] - p[idx].burstLength) {
                        gc.push_back({ p[idx].id,start_time[idx],completion_time[idx] }); //yb2a awel mara yebda2
                    }
                    else {

                        gc.push_back({ p[idx].id,completion_time[temp],completion_time[idx] });//lama ykooon bykmel
                    }
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
                gc.push_back({ p[idx].id, start_time[idx], completion_time[idx] });
                completed++;
                current_time = completion_time[idx];
            }
            else {
                current_time++;
            }

        }
    }

    return gc;
}/*
int main() {
    int n;
    cin >> n;
    vector<process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrivalTime;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burstLength;
        cout << "Enter priority";
        cin >> p[i].priority;
        p[i].id = i + 1;
        cout << endl;
    }
    Priority(p, 1);
}*/