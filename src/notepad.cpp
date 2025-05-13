#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Notepad\n";
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    filename = "./storage/" + filename;
    ofstream file;
    string line;
    while (true) {
        cout << "Enter text (q to quit, m to minimize, s to save): ";
        cin.clear();
        cin.ignore(1, '\n');
        getline(cin, line);
        if (line == "q") break;
        if (line == "m") {
            cout << "Minimizing...\n";
            sleep(1000);
            continue;
        }
        if (line == "s") {
            file.open(filename, ios::app);
            file << line << "\n";
            file.close();
            cout << "Saved!\n";
        }
    }
    cout << "Notepad closing...\n";
    return 0;
}