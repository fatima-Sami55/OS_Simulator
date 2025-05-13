#include <iostream>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include "../include/os.h"
using namespace std;

Process* process_table = nullptr;
int process_count = 0;
SystemResources resources;
sem_t resource_mutex;

void initialize_os(int ram, int hd, int cores) {
    resources.ram_total = ram;
    resources.ram_used = 0;
    resources.hd_total = hd;
    resources.hd_used = 0;
    resources.cores = cores;
    resources.cores_used = 0;
    process_table = new Process[MAX_PROCESSES];
    process_count = 0;
    sem_init(&resource_mutex, 0, 1);
}

bool allocate_resources(int ram, int hd) {
    sem_wait(&resource_mutex);
    if (resources.ram_used + ram <= resources.ram_total &&
        resources.hd_used + hd <= resources.hd_total &&
        resources.cores_used < resources.cores) {
        resources.ram_used += ram;
        resources.hd_used += hd;
        resources.cores_used++;
        sem_post(&resource_mutex);
        return true;
    }
    sem_post(&resource_mutex);
    return false;
}

void deallocate_resources(int ram, int hd) {
    sem_wait(&resource_mutex);
    resources.ram_used -= ram;
    resources.hd_used -= hd;
    resources.cores_used--;
    sem_post(&resource_mutex);
}

void schedule_processes() {
    // Simulate multilevel queue
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].state == READY) {
            process_table[i].state = RUNNING;
            // Simulate execution (in real impl, send to CPU)
            sleep(1); // Time slice
            process_table[i].burst_time--;
            if (process_table[i].burst_time <= 0) {
                process_table[i].state = TERMINATED;
                deallocate_resources(process_table[i].ram_usage, process_table[i].hd_usage);
            } else {
                process_table[i].state = READY;
            }
        }
    }
}

void switch_to_kernel_mode() {
    while (true) {
        cout << "\nKernel Mode:\n";
        cout << "1. View Processes\n2. Terminate Process\n3. Back\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nRunning Processes:\n";
            for (int i = 0; i < process_count; i++) {
                if (process_table[i].state != TERMINATED) {
                    cout << "PID: " << process_table[i].pid << ", Name: " << process_table[i].name
                         << ", State: " << process_table[i].state << "\n";
                }
            }
        } else if (choice == 2) {
            cout << "Enter PID to terminate: ";
            int pid;
            cin >> pid;
            terminate_process(pid);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid option!\n";
        }
    }
}

void shutdown_os() {
    cout << "Shutting down MiniOS";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << "\nGoodbye!\n";
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].state != TERMINATED) {
            kill(process_table[i].pid, SIGTERM);
        }
    }
    delete[] process_table;
    sem_destroy(&resource_mutex);
}