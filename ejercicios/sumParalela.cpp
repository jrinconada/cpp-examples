#include <iostream>
#include <thread>
#include <chrono>

void printTime(std::chrono::system_clock::time_point time) {
	std::time_t timeStamp = std::chrono::system_clock::to_time_t(time);
	std::cout << std::ctime(&timeStamp) << std::endl;
}

long getNumber() {
    long number;
    std::cout << "Dame un número: ";
    std::cin >> number;
    return number;
}

long sum(long number) {
    long result = 0;
    for (long i = 0; i < number; i++) {
        result++;
    }
    return result;
}

void task(long number, long& result) {
    result = sum(number);
}

int main() {
    printTime(std::chrono::system_clock::now());

    long sum1 = 0, sum2 = 0;
    std::thread t1(task, 300000000, std::ref(sum1));
    std::thread t2(task, 300000000, std::ref(sum2));
    t1.join();
    t2.join();

    std::cout << "Suma: " << sum1 + sum2 << '\n';

    printTime(std::chrono::system_clock::now());
}
