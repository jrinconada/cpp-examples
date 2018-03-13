#include <iostream>
#include <future>
#include <thread>
using namespace std;

long multiples(int n) {
    long count = 0;
    for (long i = 0; i < 100000000; i++) {
        if (i % n == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    future<long> futureResult = async(multiples, 3654546);

    std::cout << "Calculando múltiplos..." << '\n';
    // El hilo actual se queda parado
    long result = futureResult.get(); // Sólo se puede llamar a get una vez

    std::cout << result << " múltiplos" << '\n';
}
