#include <iostream>
#include <vector>

bool greaterThan10 (int x) {
    return x < 10;
}

void print(std::vector<int> numbers) {
    for (auto i = numbers.begin(); i != numbers.end(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
}

/*
    En stl existen algoritmos implementados para problemas típicos
*/
int main () {
    // ACCESO
    // La inicialización con llaves requiere C++11
    std::vector<int> numbers = {8, 2, 23, 34, 1, 4, 2, 23, 2, 7, 75};

    // Devuelve el número de elementos con el valor 2
    std::cout << count(numbers.begin(), numbers.end(), 2) << '\n';
    // Devuelve el número de elemenos que cumplen la condición dada
    // Se puede pasar una función lambda (función sin nombre)
    std::cout << count_if(numbers.begin(), numbers.end(), [](int x) {return x < 10;}) << '\n';
    // También se puede crear un función normal con la cabecera adecuada
    std::cout << count_if(numbers.begin(), numbers.end(), greaterThan10) << '\n';

    // El elemento más grande dentro de los 5 primeros
    auto iterator = max_element(numbers.begin(), numbers.begin() + 5);
    std::cout << *iterator << '\n';

    // Búsqueda lineal
    iterator = find(numbers.begin(), numbers.end(), 2);
    if (iterator == numbers.end()) {
        std::cout << "No encontrado" << '\n';
    } else {
        std::cout << "Encontrado: " << *iterator << '\n';
    }

    // ¿Es alguno mayor de 70?
    std::cout << any_of(numbers.begin(), numbers.end(), [](int x) {return x > 70;}) << '\n';
    // ¿Son todos mayores que 0?
    std::cout << all_of(numbers.begin(), numbers.end(), [](int x) {return x > 0;}) << '\n';
    // ¿Ninguno es mayor que 100?
    std::cout << none_of(numbers.begin(), numbers.end(), [](int x) {return x > 100;}) << '\n';

    // ORDENACIÓN
    print(numbers);
    // Ordenar de menor a mayor
    sort(numbers.begin(), numbers.end());
    print(numbers);
    // Ordenar de mayor a menor
    sort(numbers.begin(), numbers.end(), [](int a, int b) {return a > b;});
    print(numbers);
}
