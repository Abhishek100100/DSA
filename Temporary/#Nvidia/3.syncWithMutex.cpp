#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

// Shared variable
long long shared_counter = 0;

// Mutex to protect the shared_counter
std::mutex counter_mutex;

void increment_without_lock() {
    for (int i = 0; i < 100000; ++i) {
        // RACE CONDITION: This operation is not atomic.
        // It involves: 1. Read value, 2. Increment value, 3. Write value back.
        // A thread can be interrupted between these steps.
        shared_counter++;
    }
}

void increment_with_lock() {
    for (int i = 0; i < 100000; ++i) {
        // Use std::lock_guard for safe, exception-proof locking.
        // The mutex is acquired on construction and released on destruction.
        std::lock_guard<std::mutex> lock(counter_mutex);
        shared_counter++;
    }
}

void run_test(void (*target_function)(), const std::string& test_name) {
    shared_counter = 0; // Reset counter
    std::vector<std::thread> threads;

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(target_function);
    }
    for (auto& th : threads) {
        th.join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "--- " << test_name << " ---\n";
    std::cout << "Expected value: 500000\n";
    std::cout << "Actual value:   " << shared_counter << "\n";
    std::cout << "Time taken: " << elapsed.count() << " seconds\n\n";
}

int main() {
    run_test(increment_without_lock, "Test Without Mutex Lock");
    run_test(increment_with_lock, "Test With Mutex Lock");
    return 0;
}
