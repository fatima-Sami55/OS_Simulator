#include <iostream>
#include <ctime>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void* clock_thread(void* arg) {
    while (true) {
        time_t now = time(0);
        cout << "Time: " << ctime(&now);
        cout.flush();
        sleep(60); // Update every minute
    }
    return nullptr;
}

int main() {
    cout << "MiniOS Clock\n";
    pthread_t tid;
    pthread_create(&tid, nullptr, clock_thread, nullptr);
    pthread_join(tid, nullptr);
    return 0;
}