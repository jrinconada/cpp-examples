#include <iostream>

class Something {
public:
    int number;
    int* pointer;

    Something(int n, int p) {
        number = n;
        pointer = new int(p);
    }
};

class SomethingDeep {
public:
    int number;
    int* pointer;

    SomethingDeep(int n, int p) {
        number = n;
        pointer = new int(p);
    }

    // Copy constructor: Los punteros apuntan o una nueva dirección de memoria
    SomethingDeep(const SomethingDeep& something) {
        number = something.number;
        pointer = new int(*something.pointer);
    }
};

class SomethingUnique {
public:
    char letter;
    char* text;
private: // Copy constructor privado hace que no se puedan hacer copias
    SomethingUnique(const SomethingUnique& SomethingUnique);
};

// Función para imprimir los objetos y comprobar sus valores
void printObjects(SomethingDeep& something, SomethingDeep& copy) {

}

int main() {
    // SHALLOW COPY: Sólo se duplican los tipos básicos
    // Los punteros apuntan a los mismos contenidos
    Something something(2, 5);
    Something copy = something;
    copy.number = 4; // Se crea un nuevo entero
    *copy.pointer = 7; // Se modifica el contenido de pointer en something y copy

    // Imprime los valores de los objetos
    std::cout << "SHALLOW COPY" << '\n';
    std::cout << "Something number: " << something.number << '\n';
    std::cout << "Something pointer: " << *something.pointer << '\n';
    std::cout << "Copy number: " << copy.number << '\n';
    std::cout << "Copy pointer: " << *copy.pointer << '\n';


    // DEEP COPY: Se reserva memoria creando una copia de los datos en otro sitio
    SomethingDeep somethingDeep(2, 5);
    SomethingDeep copyDeep = somethingDeep;
    copyDeep.number = 4; // Se crea un nuevo entero
    *copyDeep.pointer = 7; // Se modifica el contenido de pointer sólo en copyDeep

    // Imprime los valores de los objetos
    std::cout << "DEEP COPY" << '\n';
    std::cout << "Something number: " << somethingDeep.number << '\n';
    std::cout << "Something pointer: " << *somethingDeep.pointer << '\n';
    std::cout << "Copy number: " << copyDeep.number << '\n';
    std::cout << "Copy pointer: " << *copyDeep.pointer << '\n';
}
