#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Copy File\n";
    cout << "Enter source filename: ";
    string src;
    cin >> src;
    src = "./storage/" + src;
    cout << "Enter destination filename: ";
    string dest;
    cin >> dest;
    dest = "./storage/" + dest;
    ifstream s(src);
    ofstream d(dest);
    if (s.is_open() && d.is_open()) {
        d << s.rdbuf();
        cout << "File copied!\n";
        s.close();
        d.close();
    } else {
        cout << "Failed to copy file!\n";
    }
    sleep(2);
    cout << "Copy File closing...\n";
    return 0;
}