#include <iostream>
#include <string>

/*
    Generalización: Relación "es un" (herencia), un Perro es un Animal
    Asociación: Relaciones entre clases, pueden ser composición o agregación
    Composición: Relación "tiene un", Persona tiene un Nombre (el Nombre no existe sin la Persona)
    Agregación: Relación en la que las clases tienen ciclos de vida independientes
    Dependencia: Una
*/

// Un nombre no existe por si sólo, debe ser de una Persona (composición)
class FullName {
public:
    std::string name;
    std::string surname;
    FullName(std::string n, std::string s) : name(n), surname(s) {}
};

// Una casa puede existir por sí sola o puede estar asociada con una o varias personas (agregación)
class House {
public:
    std::string street;
    int number;
    House (std::string s, int n) : street(s), number(n) {}
};

// Una persona tiene nombre y casa (opcional)
// El nombre es obligatorio (dependencia)
class Person {
    FullName fullName;
    House* house;
public:
    Person (FullName n, House* h = nullptr) : fullName(n), house(h) {}

    void print () { // Imprime la información
        std::cout << "Soy " << fullName.name;
        if (house != nullptr) {
            std::cout << " y vivo en " << house->street << " "
            << house->number << '\n';
        } else {
            std::cout << " y vivo en la calle" << '\n';
        }

    }
};

// Un Empleado es una Persona (generalización o herencia)
class Employee : public Person {
public:
    Employee (FullName n, House* h = nullptr) : Person(n, h) {}
};

int main () {
    Person person1(FullName("Aitor", "Tilla")); // Persona sin casa
    House* house = new House("Calle Falsa", 123); // Casa sin personas
    House* house2 = new House("Calle Principal", 5); // Casa con personas
    Person person2(FullName("Chilindra", "Pérez"), house2); // Persona con casa
    Employee employee(FullName("Pepe", "García"), house2); // Empleado (y por lo tanto Persona) con casa

    person1.print();
    person2.print();
    employee.print();
}
