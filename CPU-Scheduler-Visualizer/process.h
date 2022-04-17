#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    unsigned int id;//Process IDs start from 1 (Process ID 0 is reserved)
    unsigned int arrivalTime;
    unsigned int burstLength;
    unsigned int priority;
} process;

#endif // PROCESS_H
