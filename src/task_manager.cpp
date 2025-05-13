#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "MiniOS Task Manager\n";
    ifstream file("/proc/self/stat");
    if (file.is_open()) {
        string line;
        getline(file, line);
        cout << "Process Info: " << line << "\n";
        file.close();
    } else {
        cout << "Failed to read process info!\n";
    }
    cout << "Press q to quit: ";
    char c;
    cin >> c;
    cout << "Task Manager closing...\n";
    return 0;
}