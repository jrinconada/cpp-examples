#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

void printTime(std::chrono::system_clock::time_point time) {
	std::time_t timeStamp = std::chrono::system_clock::to_time_t(time);
	std::cout << std::ctime(&timeStamp) << std::endl;
}

mutex knife;
mutex oven;

#include "chef.cpp"

void start(Chef c) {
    c.cook();
}

int main() {
    printTime(std::chrono::system_clock::now());
    Chef c1(1);
    c1.recipes.push_back(Recipe(2, 3));
    c1.recipes.push_back(Recipe(1, 2));
    Chef c2(2);
    c2.recipes.push_back(Recipe(4, 2));
    c2.recipes.push_back(Recipe(3, 1));

    thread t1(start, c1);
    thread t2(start, c2);
    t1.join();
    t2.join();
    printTime(std::chrono::system_clock::now());
}
