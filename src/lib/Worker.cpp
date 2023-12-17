#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <memory>

#include "Worker.hpp"

Worker::Worker(int id, std::mutex& mtx, std::shared_ptr<int> data, std::shared_ptr<int> semaphore)
    : id(id), mtx(mtx), data(data), semaphore(semaphore) {}

void Worker::operator()() {
    std::unique_lock<std::mutex> lock(mtx);

    (*semaphore)++;
    int localData = *data;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulează operații asupra datelor
    *data = localData + 1;
    (*semaphore)--;

    std::cout << "Worker " << id << ": Incremented data to " << *data << std::endl;
}
