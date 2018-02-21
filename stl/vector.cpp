#include <iostream>
#include <vector>

int main() {
    // Array dinámico (puede cambiar de tamaño)
    std::vector<int> numbers;
    // Añadir elemento al final
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // for i para recorrer igual que un array
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << '\n';
    }

    numbers.erase(numbers.begin()); // Borrar el primer elemento
    // También se puede usar un for each (C++11)
    for(int& number : numbers) {
        std::cout << number << '\n';
    }

    numbers.insert(numbers.begin() + 1, 1); // Añadir en la segunda posición
    numbers.pop_back(); // Quitar el último elemento
    // Usando iteradores en el for
    std::vector<int>::iterator i; // Definición del iterador
    for (i = numbers.begin(); i < numbers.end(); i++) {
        std::cout << *i << '\n';
    }

    std::cout << numbers.empty() << '\n'; // ¿Está vacío?
    std::cout << numbers.front() << '\n'; // Primer elemento
    std::cout << numbers.back() << '\n'; // Último elemento
    numbers.clear(); // Borrar todos
    std::cout << numbers.empty() << '\n';

    // MEJORAR REDIMIENTO
    // Reserva memoria evitando la recolocación del vector
    // Se usará si sabemos cuantos vamos a meter o tenemos cierta previsión
    numbers.reserve(10);
    std::cout << numbers.capacity() << '\n'; // Muestra la capacidad total
    // La variable se crea directamente dentro del vector no se copia
    numbers.emplace_back(5);
}
