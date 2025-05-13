#ifndef OS_H
#define OS_H

#include <string>
#include <semaphore.h>
using namespace std;

#define MAX_PROCESSES 50
#define MAX_QUEUE 100

enum ProcessState { READY, RUNNING, BLOCKED, TERMINATED };
enum QueueLevel { ROUND_ROBIN, PRIORITY, FCFS };

struct Process {
    int pid;
    string name;
    int ram_usage; // MB
    int hd_usage;  // MB
    ProcessState state;
    QueueLevel level;
    int priority;  // For PRIORITY queue
    int burst_time; // For scheduling
};

struct SystemResources {
    int ram_total;  // MB
    int ram_used;
    int hd_total;  // MB
    int hd_used;
    int cores;
    int cores_used;
};

extern Process* process_table;
extern int process_count;
extern SystemResources resources;
extern sem_t resource_mutex;

void initialize_os(int ram, int hd, int cores);
bool allocate_resources(int ram, int hd);
void deallocate_resources(int ram, int hd);
void schedule_processes();
void switch_to_kernel_mode();
void shutdown_os();
void terminate_process(int pid);

#endif