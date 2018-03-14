#include <iostream>
#include <thread>
#include <vector>

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
    result += sum(number);
}

int main() {
    long number;
    long result = 0;
    std::vector<std::thread> sums;

    do {
        number = getNumber();
        sums.push_back(std::thread(task, number, std::ref(result)));
    } while(number > 0);

    for (auto& t : sums) {
        t.join();
    }
    std::cout << "Suma total: " << result << '\n';
}
