#include <iostream>

void byValue(int value) {
    value++;
}

void withPointer(int* pointer) {
    (*pointer)++; // Usar paréntesis para evitar que se ejecute antes ++
}

void byReference(int& reference) {
    reference++;
}

int main() {
    // PUNTEROS
    // Puntero sin tipo apuntando a nada
    void* pointer = nullptr; // También podemos usar NULL o 0

    int integer = 8;
    // Puntero a entero
    int* integerPointer = &integer; // & obtiene la dirección de una variable
    // * acceso al entero al que apunta
    *integerPointer = 10;

    std::cout << "Dirección: " << integerPointer << '\n';
    std::cout << "Valor: " << *integerPointer << '\n';

    // Valor constante, puntero variable (cosnt int* = int const*)
    const int* constant = new int(2);
    // Valor variable, puntero constante
    int* const constantPointer = new int(4);

    std::cout << *constant << '\n';
    std::cout << *constantPointer << '\n';

    // REFERENCIAS
    // Referencia (alias apuntando al contenido de una variable)
    int& integerReference = integer;
    std::cout << "Valor: " << integerReference << '\n';
    // Si cambia el valor de la posición de memoria cambia integerReference y integer
    integerReference = 20;
    std::cout << "Valor: " << integer << '\n';

    byValue(integer); // Se crea una nueva variable con el valor de integer
    std::cout << "Valor: " << integer << '\n';

    withPointer(&integer); // Se pasa la dirección
    std::cout << "Valor: " << integer << '\n';

    byReference(integer); // Se crea un referencia a integer
    std::cout << "Valor: " << integer << '\n';
}
