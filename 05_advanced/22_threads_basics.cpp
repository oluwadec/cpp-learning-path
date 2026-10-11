// Topic 22: Threads Basics
// A thread lets part of your program run at the same time as another part.
// When threads share a variable, a mutex makes them take turns.
//
// Compile: g++ -std=c++17 -Wall -Wextra -pthread -o threads_basics 22_threads_basics.cpp
// Run:     ./threads_basics

#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::mutex printLock;                   // protects std::cout so lines do not get mixed up
std::mutex counterLock;                 // protects the shared counter
int sharedCounter = 0;

// A function that a thread will run.
void sayHello(const std::string& who, int number) {
    std::lock_guard<std::mutex> lock(printLock);    // locked until the end of the function
    std::cout << "Hello from " << who << " (thread " << number << ")\n";
}

// Each thread adds 1000 to the shared counter, one at a time.
void addToCounter() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(counterLock);
        ++sharedCounter;
    }
}

// Adds up part of a vector and stores the answer in "result".
void sumPart(const std::vector<int>& values, int start, int end, long long& result) {
    long long total = 0;
    for (int i = start; i < end; ++i) {
        total += values[i];
    }
    result = total;
}

int main() {
    // --- Starting and joining threads ---
    std::thread t1(sayHello, "Ada", 1);
    std::thread t2(sayHello, "Bola", 2);

    t1.join();                          // wait for the thread to finish
    t2.join();

    // --- Many threads, one shared counter ---
    std::vector<std::thread> workers;
    for (int i = 0; i < 4; ++i) {
        workers.push_back(std::thread(addToCounter));
    }
    for (std::thread& w : workers) {
        w.join();
    }
    std::cout << "\nCounter (should be 4000): " << sharedCounter << '\n';

    // --- Splitting work between two threads ---
    std::vector<int> numbers;
    for (int i = 1; i <= 1000; ++i) {
        numbers.push_back(i);
    }

    long long firstHalf = 0;
    long long secondHalf = 0;

    std::thread left(sumPart, std::cref(numbers), 0, 500, std::ref(firstHalf));
    std::thread right(sumPart, std::cref(numbers), 500, 1000, std::ref(secondHalf));
    left.join();
    right.join();

    std::cout << "Sum of 1 to 1000: " << firstHalf + secondHalf << " (should be 500500)\n";

    // --- A thread using a lambda ---
    std::thread lambdaThread([]() {
        std::lock_guard<std::mutex> lock(printLock);
        std::cout << "\nHello from a lambda thread\n";
    });
    lambdaThread.join();

    return 0;
}
