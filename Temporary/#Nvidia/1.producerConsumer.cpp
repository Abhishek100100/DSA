#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <semaphore> // For std::counting_semaphore (C++20)
#include <mutex>
#include <chrono>

// Configuration
constexpr int BUFFER_SIZE = 5;
constexpr int MAX_ITEMS = 20;

// Shared resources
std::queue<int> buffer;
std::mutex buffer_mutex;
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);
std::counting_semaphore<BUFFER_SIZE> filled_slots(0);

// Global counters
int produced_count = 0;
int consumed_count = 0;

void producer() {
    while (true) {
        // Produce an item
        int item = rand() % 100 + 1;
        
        // Wait for an empty slot to be available
        empty_slots.acquire();
        
        // Use a lock_guard for safe mutex handling (critical section)
        {
            std::lock_guard<std::mutex> lock(buffer_mutex);
            if (produced_count >= MAX_ITEMS) {
                // Done producing, release the locks for the consumer to finish
                empty_slots.release();
                break;
            }
            buffer.push(item);
            produced_count++;
            std::cout << "Producer produced item " << item << ". Buffer size: " << buffer.size() << std::endl;
        } // Mutex is automatically released here
        
        // Signal that a new item is available
        filled_slots.release();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
    }
}

void consumer() {
    while (true) {
        // Wait for an item to be available
        filled_slots.acquire();

        // Use a lock_guard for safe mutex handling (critical section)
        {
            std::lock_guard<std::mutex> lock(buffer_mutex);
            if (consumed_count >= MAX_ITEMS) {
                // Done consuming, release lock for producer to exit
                filled_slots.release();
                break;
            }
            int item = buffer.front();
            buffer.pop();
            consumed_count++;
            std::cout << "Consumer consumed item " << item << ". Buffer size: " << buffer.size() << std::endl;
        } // Mutex is automatically released here

        // Signal that an empty slot is now available
        empty_slots.release();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 800));
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    std::cout << "Starting Producer and Consumer...\n";
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    std::cout << "Producer and Consumer have finished.\n";
    return 0;
}