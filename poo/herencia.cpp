#include <iostream>

class Animal {
public:
    int eyes;
    void breathe() {
        std::cout << "Respirando..." << '\n';
    }
};

// public permite el acceso a los elementos públicos de Animal
class Dog : public Animal {
public:
    int paws;
    void bark() {
        std::cout << "Guau" << '\n';
    }
};

class Fish {
    int fins;
};

// Se puede heredar de varias clases: un tiburón es un animal y un pez
class Shark: public Animal, public Fish {
public:
    int teeth;
    void nadar() {
        std::cout << "Glub glub" << '\n';
    }
};

int main() {
    // Polimorfismo: Dog y Fish son Animal y puenden estar en variables Animal
    Animal animal; // animal es un Animal
    Dog dog; // dog es un Dog y un Animal
    Animal animal2 = dog; // animal2 es un Dog y un Animal

    animal.breathe();
    dog.breathe();
    dog.bark();
    animal2.breathe();
}
