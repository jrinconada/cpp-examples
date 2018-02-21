#include <iostream>
#include <thread>
using namespace std;

void task (string& message) {
    message += " ,soy un hilo";
    std::cout << "Hilo: "<< message << '\n';
}

int main () {
    string text = "Hola que tal";
    thread t(task, std::ref(text)); // Para pasar por referencia hay que usar ref

    t.join();

    std::cout << "Main: " << text << '\n';
}
