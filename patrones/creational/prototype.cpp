#include <iostream>

class Animal {
public:
    virtual Animal* clone() = 0;
};

class Sheep: public Animal {
public:
    int state; // El estado debería ser algo complejo para que la clonación sea necesaria
    Sheep(int a) : state(a) {}
    Sheep(const Sheep& other) : state(other.state) {}

    Animal* clone() {
         return new Sheep(*this); // Se llama al copy contructor del padre
    }
};

int main () {
    Sheep derived(5);
    // Se crea una copia usando la clase padre y se hace un casting a la clase hija
    Sheep* clone = (Sheep*) derived.clone();

    std::cout << derived.state << '\n';
    std::cout << clone->state << '\n';
}
