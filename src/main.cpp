#include <iostream>
#include <unistd.h>
#include "../include/os.h"
#include "../include/tasks.h"
using namespace std;

void display_boot() {
    cout << "Welcome to MiniOS\n";
    cout << "Loading";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << "\nBoot complete!\n";
}

int main() {
    int ram, hd, cores;
    cout << "Enter RAM (MB): ";
    cin >> ram;
    cout << "Enter Hard Drive (MB): ";
    cin >> hd;
    cout << "Enter CPU Cores: ";
    cin >> cores;

    initialize_os(ram, hd, cores);
    initialize_tasks();
    display_boot();

    // Auto-start Clock and Calendar
    create_process("Clock");
    create_process("Calendar");

    while (true) {
        cout << "\nMiniOS Menu:\n";
        cout << "1. Run Task\n2. Task Manager\n3. Kernel Mode\n4. Shutdown\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nAvailable Tasks:\n";
            for (int i = 0; i < task_count; i++) {
                cout << i + 1 << ". " << tasks[i].name << "\n";
            }
            cout << "Select task number: ";
            int task_id;
            cin >> task_id;
            if (task_id > 0 && task_id <= task_count) {
                create_process(tasks[task_id - 1].name);
            } else {
                cout << "Invalid task!\n";
            }
        } else if (choice == 2) {
            create_process("Task Manager");
        } else if (choice == 3) {
            switch_to_kernel_mode();
        } else if (choice == 4) {
            shutdown_os();
            break;
        } else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}