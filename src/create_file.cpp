#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Create File\n";
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    filename = "./storage/" + filename;
    ofstream file(filename);
    if (file.is_open()) {
        cout << "File created!\n";
        file.close();
    } else {
        cout << "Failed to create file!\n";
    }
    sleep(2);
    cout << "Create File closing...\n";
    return 0;
}