#include <iostream>
#include <time.h>

int main() {
    clock_t start = clock(); // Número de ticks del reloj del sistema

    for (size_t i = 0; i < 1000000; i++) {
        std::cout << i << '\n';
    }

    float elapsedTicks = (clock() - start);
    std::cout << elapsedTicks / CLOCKS_PER_SEC << '\n';
}
