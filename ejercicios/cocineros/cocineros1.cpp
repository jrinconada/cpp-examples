#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

void printTime(std::chrono::system_clock::time_point time) {
	std::time_t timeStamp = std::chrono::system_clock::to_time_t(time);
	std::cout << std::ctime(&timeStamp) << std::endl;
}

#include "chef.cpp"

void start(Chef c) {
    c.cook();
}

int main() {
    printTime(std::chrono::system_clock::now());
    Chef c1("Pep");
    c1.recipes.push_back(new Recipe("espárragos", 2, 3));
    c1.recipes.push_back(new Recipe("pollo", 1, 2));
    Chef c2("                              Ana");
    c2.recipes.push_back(new Recipe("pescado", 4, 2));
    c2.recipes.push_back(new Recipe("lasaña", 3, 1));

    thread t1(start, c1);
    thread t2(start, c2);
    t1.join();
    t2.join();
    printTime(std::chrono::system_clock::now());
}
