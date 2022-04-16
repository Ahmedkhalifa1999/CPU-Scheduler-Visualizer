#include "FCFS.h"
/*
 Description :
 @Function takes processes a and b as inputs
 @Function Swap them in the processes vector
*/
static void swap_process(FCFS_process *a, FCFS_process *b);

/*
 Description :
 @Function takes processes vector as input
 @Function schedules the processes and place them in Gantt Chart and return the Gantt Chart
*/
GanntChart FCFS(const std::vector<FCFS_process> &processes)
{
    unsigned int n = processes.size();   /* Number of processes */
    unsigned int min_arriv;              /* min arrival time */
    unsigned int current_time = 0;       /* time on the gantt chart */
    GanntChart gc;                       /* gc is vector of slots , slot for each process */
    unsigned char flag = 1;              /*Flag used for indicating filling first slot */
    vector<FCFS_process> p = processes;

    /* Sort processes according to arrival times */
    for (unsigned int i = 0; i < n - 1; i++)
    {
        min_arriv = i;
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (p[j].arrivelTime < p[min_arriv].arrivelTime)
            {
                min_arriv = j;
            }
        }
        swap_process(&p[i], &p[min_arriv]);
    }

    /* now processes vector is sorted according to arrival times */
    /* Place processes in Gantt Chart */
    /* Number of slots = number of processes + number of idle slots */

     for (unsigned int i = 1; i < n; i++)
    {
    /* Filling First Gantt Chart slot */
    /* Assumed the first slot starts when first arrived process starts */
            if (flag)
            {
                current_time = p[0].arrivelTime + p[0].burstLength;
                gc.push_back({p[0].id , p[0].arrivelTime , current_time });
                flag = 0;
            }
            if (p[i].arrivelTime > current_time)
            {
                while (p[i].arrivelTime > current_time)
                {
                    current_time++;
                }
                 gc.push_back({0 ,  gc.back().end  , current_time });
                i--;
            }
            else if (p[i].arrivelTime <= current_time)
            {
                current_time += p[i].burstLength;
                gc.push_back({p[i].id , gc.back().end , current_time });
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

