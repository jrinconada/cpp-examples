#include <iostream>

int main() {
    // Strings de la manera clásica de C (array de char)
    // Se pone const para indicar que no puede cambiar de longitud
    char text[] = "Hola que tal"; // Podría declararse como char text[]
    std::cout << text << '\n';
    std::cout << text[5] << '\n';

    // Funciones
    std::cout << strlen(text) << '\n'; // Longitud
    char text2[24];
    strcpy(text2, text); // Copia text en text2
    std::cout << text2 << '\n';
    text2[5] = 'k'; // Poner un k en lugar de la q
    if (strcmp(text, text2) == 0) { // 0 si son iguales
        std::cout << "Iguales" << '\n';
    } else {
        std::cout << "Son distintas" << '\n';
    }

    // Escribir varias líneas en C++11
    /*const char* paragraph = R"(
        En un lugar de la mancha,
        de cuyo nombre no quiero acordarme...
                            - Cervantes
    )";
    std::cout << paragraph << '\n';*/
}
