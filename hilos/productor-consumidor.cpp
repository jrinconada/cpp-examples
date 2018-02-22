#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std;

void consume() {
    std::cout << "Consumiendo...\n";
    this_thread::sleep_for(std::chrono::seconds(3));
}

void produce() {
    std::cout << "Produciendo...\n";
    this_thread::sleep_for(std::chrono::seconds(1));
}

mutex mu;
condition_variable condition;
void notify() {
    unique_lock<mutex> lock(mu);
    condition.notify_one();
    std::cout << "notify\n";
}
void wait() {
    unique_lock<mutex> lock(mu);
    std::cout << "Esperando...\n";
    condition.wait(lock);
}

void consumer() {
    while (true) {
        wait();
        consume();
    }
}

void producer() {
    while (true) {
        produce();
        notify();
    }
}

int main() {
    std::thread c(consumer);
    std::thread p(producer);
    c.join();
    p.join();
}
