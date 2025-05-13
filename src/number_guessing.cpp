#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    cout << "MiniOS Number Guessing Game\n";
    cout << "Guess a number between 1 and 100\n";
    while (true) {
        cout << "Enter guess (q to quit, m to minimize): ";
        string input;
        cin >> input;
        if (input == "q") break;
        if (input == "m") {
            cout << "Minimizing...\n";
            sleep(1000);
            continue;
        }
        int guess = stoi(input);
        if (guess == number) {
            cout << "Correct! You win!\n";
            break;
        } else if (guess < number) {
            cout << "Too low!\n";
        } else {
            cout << "Too high!\n";
        }
    }
    cout << "Game closing...\n";
    return 0;
}