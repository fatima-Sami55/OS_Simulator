#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Move File\n";
    cout << "Enter source filename: ";
    string src;
    cin >> src;
    src = "./storage/" + src;
    cout << "Enter destination filename: ";
    string dest;
    cin >> dest;
    dest = "./storage/" + dest;
    if (rename(src.c_str(), dest.c_str()) == 0) {
        cout << "File moved!\n";
    } else {
        cout << "Failed to move file!\n";
    }
    sleep(2);
    cout << "Move File closing...\n";
    return 0;
}