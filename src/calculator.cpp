#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "MiniOS Calculator\n";
    while (true) {
        cout << "Enter operation (+, -, *, /) or q to quit, m to minimize: ";
        char op;
        cin >> op;
        if (op == 'q') break;
        if (op == 'm') {
            cout << "Minimizing...\n";
            sleep(1000); // Simulate minimize
            continue;
        }
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Invalid operation!\n";
            continue;
        }
        cout << "Enter two numbers: ";
        double a, b;
        cin >> a >> b;
        switch (op) {
            case '+': cout << "Result: " << a + b << "\n"; break;
            case '-': cout << "Result: " << a - b << "\n"; break;
            case '*': cout << "Result: " << a * b << "\n"; break;
            case '/': cout << (b != 0 ? "Result: " + to_string(a / b) : "Error: Divide by zero") << "\n"; break;
        }
    }
    cout << "Calculator closing...\n";
    return 0;
}