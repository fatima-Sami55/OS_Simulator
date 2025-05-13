#ifndef TASKS_H
#define TASKS_H

#include <string>
using namespace std;

struct Task {
    string name;
    string executable;
    int ram_usage; // MB
    int hd_usage;  // MB
    bool is_background;
    int priority;  // 1 (high) to 5 (low)
};

extern Task* tasks;
extern int task_count;

void initialize_tasks();
void create_process(string task_name);
void minimize_process(int pid);
void terminate_process(int pid);

#endif