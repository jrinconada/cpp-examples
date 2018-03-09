#include <iostream>

class Shipment {
protected:
    Shipment *next;
public:
    Shipment() {
        next = NULL;
    }

    virtual void request(int value) = 0; // Define una petición a la clase

    void setNextShipment(Shipment *shipment) { // Define el siguiente en la cadena de responsabilidad
        next = shipment;
    }
};

class ByMotorcycle : public Shipment {
    static const int maxWeight = 20;
public:
    void request(int value) {
        if(value <= maxWeight) { // Puede encargarse de la petición
            std::cout << "Se transportará en moto" << '\n';
        } else if(next != NULL) { // Delega al siguiente
            next->request(value);
        } else { // No hay más posibilidades
            std::cout << "No se transportará" << '\n';
        }
    }
};

class ByCar : public Shipment {
    static const int maxWeight = 100;
public:
    void request(int value) {
        if(value <= maxWeight) { // Puede encargarse de la petición
            std::cout << "Se transportará en furgoneta" << '\n';
        } else if(next != NULL) { // Delega al siguiente
            next->request(value);
        } else { // No hay más posibilidades
            std::cout << "No se transportará" << '\n';
        }
    }
};

class ByBoat : public Shipment {
    static const int maxWeight = 2000;
public:
    void request(int value) {
        if(value <= maxWeight) { // Puede encargarse de la petición
            std::cout << "Se transportará en barco" << '\n';
        } else if(next != NULL) { // Delega al siguiente
            next->request(value);
        } else { // No hay más posibilidades
            std::cout << "No se transportará" << '\n';
        }
    }
};

int main() {
    Shipment *moto = new ByMotorcycle();
    Shipment *boat = new ByBoat();
    Shipment *car = new ByCar();

    moto->setNextShipment(car);
    car->setNextShipment(boat);

    std::cout << "Ballena: " << '\n';
    moto->request(50000);
    std::cout << "Ferrari: " << '\n';
    moto->request(1500);
    std::cout << "Ruperto: " << '\n';
    moto->request(80);
    std::cout << "Arroz: " << '\n';
    moto->request(1);
}
