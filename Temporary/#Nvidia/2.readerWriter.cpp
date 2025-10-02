#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

// Shared resource
std::string shared_data = "Initial Data";
std::mutex resource_mutex;
std::mutex read_count_mutex;
int reader_count = 0;

void reader(int id) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Reader " << id << " is waiting to read.\n";

        // --- Reader Entry Section ---
        read_count_mutex.lock();
        reader_count++;
        // If this is the first reader, it must lock the resource from writers.
        if (reader_count == 1) {
            resource_mutex.lock();
        }
        read_count_mutex.unlock();

        // --- Critical Section for Reading ---
        std::cout << "Reader " << id << " is READING: '" << shared_data << "'\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        
        // --- Reader Exit Section ---
        read_count_mutex.lock();
        reader_count--;
        // If this is the last reader, it must unlock the resource for writers.
        if (reader_count == 0) {
            resource_mutex.unlock();
        }
        read_count_mutex.unlock();
        
        std::cout << "Reader " << id << " has finished reading.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
    }
}

void writer(int id) {
    for (int i = 0; i < 2; ++i) {
        std::cout << "Writer " << id << " is waiting to write.\n";

        // --- Writer Section (acquires exclusive lock) ---
        resource_mutex.lock();
        
        // --- Critical Section for Writing ---
        std::cout << "Writer " << id << " is WRITING.\n";
        shared_data = "Written by Writer " + std::to_string(id) + " at " + std::to_string(time(0));
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1500));
        
        resource_mutex.unlock();
        
        std::cout << "Writer " << id << " has finished writing.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1500));
    }
}

int main() {
    srand(time(0));
    std::vector<std::thread> threads;

    // Create 3 reader threads and 2 writer threads
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(reader, i + 1);
    }
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(writer, i + 1);
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "All threads have finished.\n";
    return 0;
}
