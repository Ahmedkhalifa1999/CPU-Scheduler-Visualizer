#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    unsigned int process; // Process IDs start from 1 (Process ID 0 indicated idle section)
    unsigned int start;
    unsigned int end;
} GanntChartSection;

typedef struct
{
    unsigned int id; // Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivelTime;
    unsigned int burstLength;
} FCFS_process;

typedef std::vector<GanntChartSection> GanntChart; // GanntChart is a vector of GanntChartSections

/*
 Description :
 @Function takes processes vector as input
 @Function schedules the process and place them in Gantt Chart and return the Gantt Chart
*/
static void swap_process(FCFS_process *a, FCFS_process *b);

GanntChart FCFS(std::vector<FCFS_process> &processes)
{
    unsigned int n = processes.size();   /* Number of processes */
    unsigned int min_arriv;              /* min arrival time */
    unsigned int current_time = 0;       /* time on the gantt chart */
    GanntChart gc;                       /* gc is vector of slots , slot for each process */
    unsigned char flag = 1;              /*Flag used for indicating filling first slot */

    /* Sort processes according to arrival times */
    for (unsigned int i = 0; i < n - 1; i++)
    {
        min_arriv = i;
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (processes[j].arrivelTime < processes[min_arriv].arrivelTime)
            {
                min_arriv = j;
            }
        }
        swap_process(&processes[i], &processes[min_arriv]);
    }

    /* now processes vector is sorted according to arrival times */
    /*for (unsigned int i = 0; i < n; i++)
    {
        cout << processes[i].id << " ";
    }
    cout << '\n';*/

    /* Place processes in Gantt Chart */
    /* Number of slots = number of processes + number of idle slots */

     for (unsigned int i = 1; i < n; i++)
    {
    /* Filling First Gantt Chart slot */
    /* Assumed the first slot starts when first arrived process starts */
            if (flag)
            {
                current_time = processes[0].arrivelTime + processes[0].burstLength;
                gc.push_back({processes[0].id , processes[0].arrivelTime , current_time });
                flag = 0;
            }
            if (processes[i].arrivelTime > current_time)
            {
                while (processes[i].arrivelTime > current_time)
                {
                    current_time++;
                }
                 gc.push_back({0 ,  gc.back().end  , current_time });
                i--;
            }
            else if (processes[i].arrivelTime <= current_time)
            {
                current_time += processes[i].burstLength;
                gc.push_back({processes[i].id , gc.back().end , current_time });
            }
    }
    return gc;
}
static void swap_process(FCFS_process *a, FCFS_process *b)
{
    FCFS_process temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    unsigned int n;                     /* number of processes input from user */
    unsigned int id;                    /* process id */
    unsigned int arriv;                 /* arrival time */
    unsigned int burst;                 /* CPU burst */
    vector<FCFS_process> processes;     /* vector hold each process with id , arrival time , CPU burst */
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
    {
       id = i + 1;
        cout << "\n id = " << id<< '\n';
        cin >> arriv;
        cout << "\n arrival time = " << arriv << '\n';
        cin >> burst;
        cout << "\n burst length = " <<burst << '\n';
        processes.push_back({id , arriv , burst});
    }

    GanntChart gc = FCFS(processes);
for (unsigned int i = 0; i < gc.size(); i++)
    {
        cout<<"id = " << gc[i].process << " start = "<< gc[i].start<<" , end = "<< gc[i].end<<'\n';

    }
    cout << '\n';
    return 0;
}
