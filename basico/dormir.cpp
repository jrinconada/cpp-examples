#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Durmiendo..." << '\n';
    sleep(2); // Detener la ejecución 2 segundos
    std::cout << "Buenos días" << '\n';
    std::cout << "Siesta..." << '\n';
    usleep(1000000); // Detener la ejecución 1 millón de microsegundos (1 segundo)
    std::cout << "Fin." << '\n';
}
