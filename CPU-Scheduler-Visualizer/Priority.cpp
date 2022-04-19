#include "Priority.h"
#include <iostream>
using namespace std;

GanntChart Priority(const std::vector<process>& p, bool preemptive) {
    GanntChart gc;
    unsigned int n = p.size();
    vector<unsigned int> burst_remaining(n);
    vector<bool> is_completed(n, false);
    vector<bool> visited(n, false);
    vector<unsigned int> start_time(n);
    vector<unsigned int> completion_time(n);
    unsigned int current_time = 0;
    unsigned int completed = 0;
    int temp = -1;//the index of the previous process
    for (unsigned int i = 0; i < n; i++) {
        burst_remaining[i] = p[i].burstLength;
    }

    if (preemptive) {
        while (completed != n) {
            int idx = -1;
            int prev = -1;
            // int temporary = -1;

            unsigned int mn = 10000; /*minimum Priority*/
            for (unsigned int i = 0; i < n; i++) {

                if (p[i].arrivalTime <= current_time && is_completed[i] == false) {
                    if (p[i].priority < mn) {
                        //index process
                        if (temp != -1 && burst_remaining[temp] != 0) {
                            prev = temp;
                        }
                        else {
                            prev = idx;
                        }
                        mn = p[i].priority;
                        idx = i;


                    }
                    if (p[i].priority == mn) {
                        if (p[i].arrivalTime < p[idx].arrivalTime) {

                            mn = p[i].priority;
                            idx = i;

                        }
                    }
                }
            }

            if (idx != -1) {
                if (burst_remaining[idx] == p[idx].burstLength) {
                    start_time[idx] = current_time;

                    if (prev != -1 && start_time[prev] == p[idx].arrivalTime - (p[prev].burstLength - burst_remaining[prev]) && burst_remaining[prev] != 0) {/* law kan bad2 men el awaal bs mkhlssh el burst kolo*/
                        if (visited[prev] != true)
                            gc.push_back({ p[prev].id,p[idx].arrivalTime - (p[prev].burstLength - burst_remaining[prev]) ,p[idx].arrivalTime });

                        temp = idx;
                        visited[prev] = true; // lama astkhdmo tany mesh hyb2a bade2 men el awal
                    }
                    else if (prev != -1 && visited[prev] == true && completion_time[temp] != current_time) {
                        gc.push_back({ p[prev].id,completion_time[temp],p[idx].arrivalTime });
                        temp = idx;
                    }
                    /*if (prev != -1 && burst_remaining[prev] != 0 && p[idx].priority < p[prev].priority) {
                        if (temp!=-1 && burst_remaining[temp]!=0&& p[prev].burstLength-burst_remaining[prev]>1 && burst_remaining[idx] == 0) {
                            gc.push_back({ p[prev].id,completion_time[temp],p[idx].arrivalTime });

                            temp = idx;
                        }
                        else if (temp != idx && burst_remaining[idx] >= 1) {
                            if (p[idx].arrivalTime == current_time && p[idx].priority<p[prev].priority) {
                                gc.push_back({ p[prev].id,start_time[prev],p[idx].arrivalTime });
                                temp = idx;

                            }

                        }
                    }*/
                    //lama ykoon lesa awel mara yeshtghal
                }




                burst_remaining[idx] -= 1;
                current_time++;


                if (burst_remaining[idx] == 0) {

                    completion_time[idx] = current_time;
                    if (start_time[idx] == completion_time[idx] - p[idx].burstLength) {
                        gc.push_back({ p[idx].id,start_time[idx],completion_time[idx] });
                        temp = idx;
                        visited[idx] = true;
                        //bada2 men el awal
                    }
                    else {
                        //if (temp != idx && temp!=-1) {
                        gc.push_back({ p[idx].id,completion_time[temp],completion_time[idx] });//lama ykooon bykmel

                        temp = idx;
                        visited[idx] = true;
                        // }
                         /*else if (prev != idx && prev != -1) {
                             gc.push_back({ p[idx].id,completion_time[prev],completion_time[idx]});
                         }*/
                    }

                    is_completed[idx] = true;
                    completed++;
                }

            }
            else {//idle
                current_time++;

            }
        }
    }

    else {
        while (completed != n) {
            int idx = -1;
            unsigned int mn = 10000;
            for (unsigned int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == false) {
                    if (p[i].priority < mn) {
                        mn = p[i].priority;
                        idx = i;
                    }
                    if (p[i].priority == mn) {
                        if (p[i].arrivalTime < p[idx].arrivalTime) {
                            mn = p[i].priority;
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
}
