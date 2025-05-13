#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Music Player\n";
    for (int i = 0; i < 5; i++) {
        system("echo -e '\a'"); // Beep
        sleep(2);
    }
    cout << "Music Player closing...\n";
    return 0;
}