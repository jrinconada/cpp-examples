#include <iostream>
#include <thread>
#include <chrono>

void printTime(std::chrono::system_clock::time_point time) {
	std::time_t timeStamp = std::chrono::system_clock::to_time_t(time);
	std::cout << std::ctime(&timeStamp) << std::endl;
}

int main() {
    std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
    printTime(std::chrono::system_clock::now());

    for (int i = 10; i > 0; i--) {
        std::cout << i << '\n';
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    std::cout << "Ignición!" << '\n';
}
