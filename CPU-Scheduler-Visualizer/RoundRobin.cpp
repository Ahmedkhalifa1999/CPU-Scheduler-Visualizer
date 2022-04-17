#include "RoundRobin.h"

using namespace std;

GanntChart RoundRobin(const std::vector<process> &processes, unsigned int timeQuantum) {

	GanntChart ganntChart;
	GanntChartSection section;
    vector<process> process = processes;

	unsigned int last = processes.size();
	unsigned int time = 0;
	unsigned int i = 0;
	bool idle = true;

	while (last > 0)
	{
		if (process[i].arrivalTime <= time && process[i].burstLength > 0)
		{
			idle = false;
			section.process = processes[i].id;
			process[i].burstLength -= timeQuantum;

			section.start = time;
			time += timeQuantum;
			section.end = time;

			ganntChart.push_back(section);

			if (process[i].burstLength <= 0)
			{
				last--;
			}

		}
		else if (process[i].arrivalTime >= time)
		{
			idle = true;
		}

		if (i == process.size() - 1 && idle)
		{
			section.process = 0;

			section.start = time;
			time += timeQuantum;
			section.end = time;

			ganntChart.push_back(section);
		}

		i = (i + 1) % processes.size();


	}

	return ganntChart;
}
