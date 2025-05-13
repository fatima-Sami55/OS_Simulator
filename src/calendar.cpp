#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Calendar\n";
    time_t now = time(0);
    tm* ltm = localtime(&now);
    cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\n";
    sleep(10); // Run briefly
    cout << "Calendar closing...\n";
    return 0;
}