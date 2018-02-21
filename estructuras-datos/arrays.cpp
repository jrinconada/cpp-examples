#include <iostream>
#include <array> // Array de C++

void mostrar(int array[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        std::cout << array[i] << std::endl;
    }
}

int main() {
    // Creado en stack (vive dentro de su ámbito, en este caso main)
    int numbers[5] = {1, 2, 3, 4, 5};
    // El tamaño del array en bytes entre el tamaño de cada elemento es la longitud
    int length = sizeof(numbers) / sizeof(int);
    mostrar(numbers, length);

    // Creado en heap (vive desde que se crea hasta que se destruye o acaba el programa)
    const unsigned short count = 5;
    int* otherArray = new int[count];
    mostrar(otherArray, 5);
    delete[] otherArray;

    // Uso de librería array, permite saber el tamaño y otras funciones interesantes
    std::array<int, 5> arrayStd;
    arrayStd.fill(3); // fill rellena el array con treses
    std::cout << arrayStd.front() << std::endl; // front obtiene el primer elemento

    // For each es una manera más cómoda de recorrer arrays en C++11
    // auto& copia por referencia de cada elemento detectando el tipo de dato
    for(auto& item : arrayStd) {
        std::cout << item << std::endl;
    }
}
