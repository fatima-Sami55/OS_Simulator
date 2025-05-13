#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <cstring>
#include <filesystem> // Line 8: Added <filesystem> include
#include "../include/os.h"
#include "../include/tasks.h"
using namespace std;

namespace fs = std::filesystem; // Line 10: Added filesystem namespace

Task* tasks = nullptr;
int task_count = 15;

void initialize_tasks() {
    tasks = new Task[task_count];
    string base_path = fs::current_path().string() + "/bin/"; // Line 18: Updated base_path to use bin/ directory
    tasks[0] = {"Calculator", base_path + "calculator", 10, 0, false, 1};
    tasks[1] = {"Notepad", base_path + "notepad", 20, 10, false, 1};
    tasks[2] = {"Clock", base_path + "clock", 5, 0, true, 3};
    tasks[3] = {"Calendar", base_path + "calendar", 5, 0, true, 3};
    tasks[4] = {"Create File", base_path + "create_file", 10, 10, false, 2};
    tasks[5] = {"Delete File", base_path + "delete_file", 10, 0, false, 2};
    tasks[6] = {"Move File", base_path + "move_file", 10, 0, false, 2};
    tasks[7] = {"Copy File", base_path + "copy_file", 10, 10, false, 2};
    tasks[8] = {"File Info", base_path + "file_info", 10, 0, false, 2};
    tasks[9] = {"Task Manager", base_path + "task_manager", 15, 0, false, 2};
    tasks[10] = {"Music Player", base_path + "music_player", 15, 0, true, 3};
    tasks[11] = {"Number Guessing", base_path + "number_guessing", 10, 0, false, 1};
    tasks[12] = {"Print File", base_path + "print_file", 10, 0, false, 2};
    tasks[13] = {"Instruction Guide", base_path + "instruction_guide", 10, 0, false, 2};
    tasks[14] = {"Dice Roller", base_path + "dice_roller", 10, 0, false, 1};
}

void create_process(string task_name) {
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].name == task_name) {
            if (!allocate_resources(tasks[i].ram_usage, tasks[i].hd_usage)) {
                cout << "Insufficient resources for " << task_name << "!\n";
                return;
            }
            pid_t pid = fork();
            if (pid == 0) {
                string command = tasks[i].executable + "; bash"; // Line 38: Modified command to keep xterm open
                const char* args[] = {"xterm", "-e", "bash", "-c", command.c_str(), nullptr}; // Line 39: Updated args to use bash -c
                execvp("xterm", const_cast<char* const*>(args));
                perror("execvp failed"); // Line 42: Added perror for execvp failure
                cout << "Failed to execute: " << tasks[i].executable << endl; // Line 43: Added failure message
                exit(1);
            } else if (pid > 0) {
                process_table[process_count].pid = pid;
                process_table[process_count].name = task_name;
                process_table[process_count].ram_usage = tasks[i].ram_usage;
                process_table[process_count].hd_usage = tasks[i].hd_usage;
                process_table[process_count].state = READY;
                process_table[process_count].level = tasks[i].is_background ? PRIORITY : ROUND_ROBIN;
                process_table[process_count].priority = tasks[i].priority;
                process_table[process_count].burst_time = 10;
                process_count++;
                schedule_processes();
            } else {
                cout << "Fork failed: " << strerror(errno) << "\n"; // Line 49: Added fork failure message
            }
            return;
        }
    }
    cout << "Task not found!\n";
}

void minimize_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid && process_table[i].state != TERMINATED) {
            process_table[i].state = BLOCKED;
            kill(pid, SIGSTOP);
            break;
        }
    }
}

void terminate_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid && process_table[i].state != TERMINATED) {
            kill(pid, SIGTERM);
            process_table[i].state = TERMINATED;
            deallocate_resources(process_table[i].ram_usage, process_table[i].hd_usage);
            break;
        }
    }
}