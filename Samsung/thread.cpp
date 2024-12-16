#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex mtx;                  // Mutex to protect shared resources
condition_variable cv;      // Condition variable for thread synchronization
bool isThreadATurn = true;       // Flag to indicate whose turn it is

void threadA() {
    while (true) {
        unique_lock<mutex> lock(mtx); // Lock the mutex
        cv.wait(lock, [] { return isThreadATurn; }); // Wait until it's thread A's turn
        cout << "A";
        isThreadATurn = false;   // Set flag for thread B's turn
        lock.unlock();           // Unlock the mutex
        cv.notify_all();         // Notify other threads
    }
}

void threadB() {
    while (true) {
        unique_lock<mutex> lock(mtx); // Lock the mutex
        cv.wait(lock, [] { return !isThreadATurn; }); // Wait until it's thread B's turn
        cout << "B";
        isThreadATurn = true;    // Set flag for thread A's turn
        lock.unlock();           // Unlock the mutex
        cv.notify_all();         // Notify other threads
    }
}

int main() {
    thread t1(threadA);
    thread t2(threadB);
    t1.join();
    t2.join();
    return 0;
}
