#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Delete File\n";
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    filename = "./storage/" + filename;
    if (remove(filename.c_str()) == 0) {
        cout << "File deleted!\n";
    } else {
        cout << "Failed to delete file!\n";
    }
    sleep(2);
    cout << "Delete File closing...\n";
    return 0;
}