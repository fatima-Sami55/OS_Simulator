#include <iostream>
#include <sys/stat.h>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS File Info\n";
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    filename = "./storage/" + filename;
    struct stat info;
    if (stat(filename.c_str(), &info) == 0) {
        cout << "Size: " << info.st_size << " bytes\n";
        cout << "Last modified: " << ctime(&info.st_mtime);
    } else {
        cout << "File not found!\n";
    }
    sleep(2);
    cout << "File Info closing...\n";
    return 0;
}