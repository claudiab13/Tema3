#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <memory>

#include "lib/Worker.hpp"

int main() {
    
    std::mutex mtx;
    std::shared_ptr<int> data = std::make_shared<int>(13);
    std::shared_ptr<int> semaphore = std::make_shared<int>(0);

    Worker worker1(1, mtx, data, semaphore);

    worker1.operator()();

    std::cout << *data << std::endl;
    return 0;
}
