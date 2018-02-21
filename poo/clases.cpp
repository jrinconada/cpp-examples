#include <iostream>

class Car {
public:
    int speed; // Variable de instancia (cada Car tiene su speed)
    static long count; // Variable de clase (compartida por todos los Cars)
private:
    float fuel;
    const static short wheels = 4; // static: mismo valor para todos los Cars
public:
    Car() { // Constructor, se llama al declarar un Car
        speed = 0;
        fuel = 0;
    }

    Car(float fuel) { // Constructor con 1 parámetros
        speed = 0;
        // this es un puntero a la entidad actual de esta clase
        this->fuel = fuel; // this-> es equivalente a (*this).fuel
    }

    // Constructor compacto con 2 parámetros
    Car(float fuel, float speed) : fuel(fuel), speed(speed) {}

    void refuel(float liters) {
        fuel += liters;
    }

    void print() {
        std::cout << wheels << " ruedas "
        << speed << " km/h "
        << fuel << " litros" << '\n';
    }

    /* Getter, método para leer una valor
    const especifica sólo lectura, getFuel no puede modificar variables
    Añadiendo mutable en la declaración de la variable se pordría modificar */
    float getFuel() const {
        return fuel;
    }

    // Destructor, se llama al teminar el ámbito donde fue creado el objeto
    ~Car() {
        std::cout << "Coche destruido" << '\n';
    }
public: // Accesible por todos
private: // Sólo accesible por la clase Animal
protected: // Accesible por la clase Animal y sus hijos
};

// Para poder usar la variable estática count hay que definirla
long Car::count = 0;

int main() {
    Car car; // Constructor con ningún parámetro
    car.refuel(10.4);
    car.speed = 50;
    Car::count++;
    car.print();

    Car car2(5.3); // Constructor de 1 parámetro
    Car::count++;
    car2.print();
    std::cout << "Número de coches: " << Car::count << '\n';

    Car car3(6.3, 75); // Constructor de 2 parámetros
    car3.print();
}
