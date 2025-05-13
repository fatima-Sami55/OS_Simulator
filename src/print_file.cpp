#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Print File\n";
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    filename = "./storage/" + filename;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "File not found!\n";
    }
    sleep(2);
    cout << "Print File closing...\n";
    return 0;
}