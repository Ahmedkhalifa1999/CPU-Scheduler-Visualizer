#include "metrics.h"
#include <list>

using namespace std;

int maximum(vector<int> z)  //function to calculate the maximum element in a vector
{
	int max = 0;
    for (unsigned int i = 0; i < z.size(); i++)
	{
		if (z[i] > max)
		{
			max = z[i];
		}
	}
	return max;
}

metrics calculateMetrics(GanntChart timeline,  const std::vector<process> &processes) {
	metrics m;
    vector<int> turnArround(processes.size() + 1);   //vector to hold the turnarround time for each process
	double totalt = 0;
    vector<int> waitingTime(processes.size() + 1);   //vector to hold the waiting time for each process
	double totalw = 0;
    vector<int> responseTime(processes.size() + 1);  //vector to hold the response time for each process
	double totalr = 0;
	list<GanntChartSection> x = timeline;
	x.reverse();
    for (unsigned int i = 0; i < processes.size(); i++)
	{
		for (GanntChartSection section : x) //iterate on reversed ganntchart to use end value of each process
		{
			if (processes[i].id == section.process)
			{
				turnArround[i] = section.end - processes[i].arrivalTime;
				waitingTime[i] = turnArround[i] - processes[i].burstLength;
				totalt += turnArround[i];
				totalw += waitingTime[i];
			}
		}
		for (GanntChartSection section : timeline)  //iterate on reversed ganntchart to use first time of each process gets cpu
		{
			if (processes[i].id == section.process)
			{
				responseTime[i] = section.start - processes[i].arrivalTime;
				totalr += responseTime[i];
			}
		}
	}
	int c = processes.size();
	m.averageResponseTime = totalr / c;
	m.averageTurnAroundTime = totalt / c;
	m.averageWaitingTime = totalw / c;
	m.maximumTurnAroundTime = maximum(turnArround);
	m.maximumWaitingTime = maximum(waitingTime);
	m.maximumResponseTime=maximum(responseTime);
	return m;
}
