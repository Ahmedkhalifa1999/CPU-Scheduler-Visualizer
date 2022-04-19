#include "RoundRobin.h"

using namespace std;

GanntChart RoundRobin(const std::vector<process> &processes, unsigned int timeQuantum) {

	GanntChart ganntChart;
	GanntChartSection section;
    vector<process> process = processes;

	int compare=0;
	unsigned int last = processes.size();
	unsigned int time = 0;
	unsigned int i = 0;
	bool idle = true;
	bool wait = false;

	while (last > 0)
	{
		if (process[i].arrivalTime <= time && process[i].burstLength > 0)
		{
			idle = false;

			section.start = time;
			section.process = processes[i].id;
			compare = process[i].burstLength;

			if (compare < timeQuantum)
			{
				time += compare;
			}
			else
			{
				time += timeQuantum;
			}

			section.end = time;

			compare -= timeQuantum;
			if (compare <= 0)
			{
				process[i].burstLength = 0;
				compare=0;
			}
			else
			{
				process[i].burstLength = compare;
			}

			ganntChart.push_back(section);

			if (process[i].burstLength == 0)
			{
				last--;
				wait = false;
			}
			else
			{
			    wait = true;
			}

		}
		else if (process[i].arrivalTime >= time)
		{
		    idle = true;
		    if (compare < process[i].arrivalTime)
		    {
		        compare = process[i].arrivalTime;
		    }

		}

		if (i == process.size() - 1 && idle && !wait)
		{
			section.process = 0;

			section.start = time;
			if ((time + timeQuantum) > compare)
			{
			    time += (compare - time);
			}
			else
			{
			    time += timeQuantum;
			}
			section.end = time;

			ganntChart.push_back(section);
		}

		i = (i + 1) % processes.size();



	}

	return ganntChart;
}
