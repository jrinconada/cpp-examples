#include <iostream>
#include <future>
#include <thread>
using namespace std;

void multiples(int n, promise<long>& promiseResult) {
    long count = 0;
    for (long i = 0; i < 100000000; i++) {
        if (i % n == 0) {
            count++;
        }
    }
    promiseResult.set_value(count);
}

void printer(long number, future<long>& futureResult) {
    std::cout << "Se están calculando los múltiplos..." << '\n';
    long result = futureResult.get();
    std::cout << number << " tiene " << result << " múltiplos"<< '\n';
}

int main() {
    promise<long> promiseResult;
    future<long> futureResult = promiseResult.get_future();

    long number = 3654546;
    // multiples promete un resultado
    thread m(multiples, number, ref(promiseResult));
    // printer tiene la promesa de un resultado para imprimir
    thread p(printer, number, ref(futureResult));

    m.join();
    p.join();
}
