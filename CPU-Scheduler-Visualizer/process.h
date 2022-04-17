#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    unsigned int id;//Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivalTime;
    unsigned int burstLength;
    unsigned int priority;

    //Temporary fields for SJF scheduler
    unsigned int completionTime;
    unsigned int startTime;
} process;

#endif // PROCESS_H
