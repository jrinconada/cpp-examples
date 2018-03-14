#include <iostream>
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

int main() {
    printTime(std::chrono::system_clock::now());

    long result = sum(300000000);
    result += sum(300000000);
    std::cout << "Suma: " << result << '\n';

    printTime(std::chrono::system_clock::now());
}
