#include <iostream>

class Vehicle {
public:
    virtual void print() = 0;
};

class Car : public Vehicle {
public:
    void print() {
        std::cout << "car" << '\n';
    }
};

class Motorcycle : public Vehicle {
public:
    void print() {
        std::cout << "bike" << '\n';
    }
};

class Van : public Vehicle {
public:
    void print() {
        std::cout << "van" << '\n';
    }
};

// La clase VehicleFactory construye los objetos de la familia Vehicle
class VehicleFactory {
public:
    static Vehicle* createVehicle(char type) {
        switch (type) {
            case 'c':
            return new Car;
            case 'm':
            return new Motorcycle;
            case 'v':
            return new Van;
            default:
            return nullptr;
        }
    }
};

int main () {
    Vehicle* vehicle = VehicleFactory::createVehicle('c');
    vehicle->print();
    vehicle = VehicleFactory::createVehicle('m');
    vehicle->print();
    vehicle = VehicleFactory::createVehicle('v');
    vehicle->print();
}
