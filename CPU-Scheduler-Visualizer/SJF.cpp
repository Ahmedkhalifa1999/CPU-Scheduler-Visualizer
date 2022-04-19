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
    int temp = -1;
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
        for (int i = 0; i < n; i++) {
            burst_remaining[i] = p[i].burstLength;
        }
        while (completed != n) {
            int idx = -1;
            int prev = -1;
            int mn = 10000000;
            for (int i = 0; i < n; i++) {
                if (p[i].arrivalTime <= current_time && is_completed[i] == 0) {
                    if (burst_remaining[i] < mn) {
                        if (temp != -1 && burst_remaining[temp] != 0) {
                            prev = temp;
                        }
                        else {
                            prev = idx;
                        }
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
                    if (prev != -1 && burst_remaining[prev] != 0 && burst_remaining[prev] > burst_remaining[idx]) {
                        if (temp != -1 && burst_remaining[temp] == 0 && p[idx].burstLength > burst_remaining[prev] && p[idx].arrivalTime > current_time && p[prev].burstLength - burst_remaining[prev] > 1) {
                            gcs.process = p[prev].id;
                            gcs.start = completionTime[temp];
                            gcs.end = p[idx].arrivalTime;        //p1 not p4  //heta felnos w lesa leha ba2y mn gher mategy haga t2t3ha
                            gc.push_back(gcs);
                            temp = idx;
                        }


                        else if (temp != idx && p[prev].burstLength - burst_remaining[prev] >= 1 && burst_remaining[idx] > 1) {
                            gcs.process = p[prev].id;
                            gcs.start = startTime[prev];    //old p1 not p4
                            gcs.end = p[idx].arrivalTime;   //heta makmltsh w gat haga at3tha bas mkhlstsh
                            gc.push_back(gcs);
                            temp = idx;
                        }


                    }
                }




                burst_remaining[idx] -= 1;
                current_time++;


                if (burst_remaining[idx] == 0) {
                    completionTime[idx] = current_time;
                    if (startTime[idx] == completionTime[idx] - p[idx].burstLength) {
                        gcs.process = p[idx].id;
                        gcs.start = startTime[idx];
                        gcs.end = completionTime[idx];   //p4  //heta bad2t w khaslt 
                        gc.push_back(gcs);
                        temp = idx;
                    }
                    else {
                        gcs.process = p[idx].id;
                        gcs.start = completionTime[temp];    //heta khalst mbd2tsh mn el awl
                        gcs.end = completionTime[idx];
                        gc.push_back(gcs);
                        temp = idx;

                    }
                    is_completed[idx] = 1;
                    completed++;
                }
            }
            else {
                current_time++;
            }
        }
    }


    return gc;

}

