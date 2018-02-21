#include <iostream>
#include <thread>

void task () {
    std::cout << "Soy el hilo" << std::this_thread::get_id() << '\n';
}

void task2 (int message) {
    std::cout << "Soy un hilo y digo: " << message << '\n';
}

int main () {
    std::thread::hardware_concurrency();
    std::thread t(task);
    std::thread t2(task2, 23); // Esta llamada sólo funciona en C++11

    // Obtener ids de los hilos
    std::cout << t.get_id() << '\n';
    std::cout << t2.get_id() << '\n';

    t.join(); // El hilo principal espera a que termine t
    t2.join(); // El hilo principal espera a que termine t2
}
