#pragma once

#include <mutex>
#include <iostream>

class Worker {
    private:
        int id;                         // id worker
        std::mutex& mtx;                // mutex - protejeaza accesul la datele partajate
        std::shared_ptr<int> data;      // smart pointer - int - datele partajate intre thread-uri
        std::shared_ptr<int> semaphore; // smart pointer - int - semafor pentru threads sync
                                        // indica cati workeri sunt in prezent in sectiunea critica 
    public:
        Worker(int id, std::mutex& mtx, std::shared_ptr<int> data, std::shared_ptr<int> semaphore);
        void operator()();


};


