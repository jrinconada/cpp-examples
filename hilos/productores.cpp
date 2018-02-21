#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include "semaphore.cpp"
using namespace std;

Semaphore semaphore;

void consume(int id) {
    std::cout << "C" << id << " consume..." << '\n';
    this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "C" << id << " fin." << '\n';
}

void produce(int id) {
    std::cout << "P" << id << " produce..." << '\n';
    this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "P" << id << " fin." << '\n';
}

void consumer(int id) {
    while (true) {
        std::cout << "C" << id << " espera..." << '\n';
        semaphore.wait();
        consume(id);
    }
}

void producer(int id) {
    while (true) {
        produce(id);
        semaphore.notify();
    }
}

int main() {
    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);
    std::thread p1(producer, 1);
    std::thread p2(producer, 2);
    c1.join();
    c2.join();
    p1.join();
    p2.join();
}
