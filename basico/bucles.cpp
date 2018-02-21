#include <iostream>
using namespace std;

/*
    argc es el número de parsámetros de programa
    argv es un array con los parámetros
    Ej: ./bucles 1 2 3   argc es 4, argv es [./bucles, 1, 2, 3]
*/
int main(int argc, char const *argv[]) {
    cout << "for de argumentos:" << endl;
    // size_t es un tipo de dato de al menos 16 bits
    for (size_t i = 1; i < argc; i++) {
        if (argv[i] == "2") {
            continue; // Si el parámetro es 2 pasa a la siguiente iteración
        }
        cout << argv[i] << endl;
    }

    cout << "while de argumentos:" << endl;
    int i = 1;
    while (i < argc) {
        if (argv[i] == "3") {
            break; // Si el parámetro es 3 termina el bucle
        }
        cout << argv[i] << endl;
        i++;
    }

    cout << "do while de argumentos:" << endl;
    i = 0; // Imprime también el nombre del programa
    do {
        cout << argv[i] << endl;
        i++;
    } while (i < argc);

    cout << "for each del array [1, 2, 3, 4, 5]:" << endl;
    int numbers[] = {1, 2, 3, 4, 5};
    // auto detecta el tipo de dato
    // for each sólo está disponible a partir de C++11
    for(auto number : numbers) {
        cout << number << endl;
    }

    return 0; // 0 si todo OK, 1 o más si hay algún error
}
