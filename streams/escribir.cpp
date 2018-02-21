#include <iostream>
#include <fstream> // Librería File Stream
using namespace std;

/*
    Output stream: Escritura de datos en serie
    Se puede escribir a un fichero, consola (cout), a la red...
    ofstream: Escritura de datos en un fichero
*/
void write (string name) {
    // Si el fichero no existe se crea
    // por defecto se escribe desde el principio sobreescribiendo los contenidos
    ofstream file;
    file.open(name); // Se puede escribir como: ofstream file("file");
    file << "Guardando un string en un fichero" << endl;
    file << "También se pueden guardar otros datos básicos: " << endl;
    file << 22 << " " << 5.5 << " " << 'g' << endl;
    file.close(); // Se cierra automáticamente al salir del ámbito
}

// Escribir al final del fichero
void append (string name) {
    ofstream file(name, ofstream::app); // Declaración y apertura en una línea
    if (file.is_open()) { // Se puede comprobar que está abierto
        file << "nuevos contenidos" << endl;
    }
} // No hace falta cerrar el fichero, se hace automáticamente al salir del ámbito

// Escribir en una posición concreta del fichero
void write (string name, int position) { // position: número de caracteres
    fstream file(name); // Apertura de fichero para lectura / escritura
    // seekp: Mueve la posición de escritura, seekg: Mueve la posición de lectura
    // ios::beg (principio del fichero) ios::cur (posición actual) ios::end (final)
    file.seekp(position, ios::beg);
    file << "SPAM";
}

int main () {
    write("file");
    append("file");
    write("file", 10);
}
