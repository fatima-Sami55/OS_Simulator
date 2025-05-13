#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    srand(time(0));
    cout << "MiniOS Dice Roller\n";
    while (true) {
        cout << "Press enter to roll (q to quit, m to minimize): ";
        string input;
        cin.clear();
        cin.ignore(1, '\n');
        getline(cin, input);
        if (input == "q") break;
        if (input == "m") {
            cout << "Minimizing...\n";
            sleep(1000);
            continue;
        }
        int roll = rand() % 6 + 1;
        cout << "You rolled: " << roll << "\n";
    }
    cout << "Dice Roller closing...\n";
    return 0;
}