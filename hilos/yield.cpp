#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

int age;

void adult() {
    while (age < 18) {
        this_thread::yield(); // Espera
    }
    std::cout << "Soy adulto, puedo conducir!" << '\n';
}

int main() {
    thread waitToDrive(adult);
    for (size_t i = 1; i < 20; i++) {
        usleep(200000); // Esperar 200 milisegundos
        std::cout << "Tengo " << i << '\n';
    }
    waitToDrive.join();
}
