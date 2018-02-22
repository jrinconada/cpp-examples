#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std;

void consume(string id) {
    std::cout << "C" + id + " consume...\n";
    this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "C" + id + " fin.\n";
}

void produce() {
    std::cout << "P1 produce...\n";
    this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "P1 fin.\n";
}

mutex mu;
condition_variable condition;
void notify() {
    unique_lock<mutex> lock(mu);
    condition.notify_one();
}
void wait(string id) {
    unique_lock<mutex> lock(mu);
    std::cout << "C" + id + " espera...\n";
    condition.wait(lock);
}

void consumer(string id) {
    while (true) {
        wait(id);
        consume(id);
    }
}

void producer() {
    while (true) {
        produce();
        notify();
    }
}

int main() {
    std::thread c1(consumer, "1");
    std::thread c2(consumer, "2");
    std::thread p(producer);
    c1.join();
    c2.join();
    p.join();
}
