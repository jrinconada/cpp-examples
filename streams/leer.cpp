#include <iostream>
#include <fstream> // Librería File Stream
using namespace std;

/*
    ifstream: Lectura de datos de un fichero
*/
void read (string name) {
    ifstream file(name); // Declaración y apertura en una línea
    string data;
    while (getline(file, data)) { // Lectura línea a línea hasta el final
        std::cout << data << '\n';
    }
} // No hace falta cerrar el fichero, se hace automáticamente al salir del ámbito

// Intenta leer un entero del fichero
void readInt (string name) {
    ifstream file(name);
    int integer;
    if (file >> integer) { // Intenta leer una palabra e interpretarla como entero
        std::cout << "Lectura correcta: " << integer << '\n';
    } else { // Si no es ha podido transformar a entero devuelve false
        std::cout << "No se ha podido leer un entero" << '\n';
    }
}


// Cálculo del tamaño de fichero usando la posición del puntero de lectura
void size (string name) {
    ifstream file(name);
    // tellg: Devuelve posición de lectura
    streampos begin = file.tellg();
    file.seekg(0, ios::end); // Mueve la posicón de lectura al final
    streampos end = file.tellg(); // Obtiene la posición de lectura

    int chars = end - begin; // Número de caracteres o bytes
    std::cout << chars << '\n';
}

int main () {
    read("file");
    size("file");
    readInt("file2");
}
