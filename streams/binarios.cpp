#include <iostream>
#include <fstream>
using namespace std;

class Person {
public:
    char nameInitial;
    int age;
    Person(char n, int a) : nameInitial(n), age(a) {}
};

template<typename T> // Se usa template para poder usar cualquier tipo de dato
void write(const char* name, T data) {
    // Apertura de fichero para escribir datos binarios (no char)
    ofstream file(name, ios::binary);
    /*
        write recibe dos parámetros: un array de chars (char*) y número de chars
        write escribe el número de caracteres del array indicado en el segundo parámetro
        sizeof devuelve el número de bytes que ocupa el dato
        &data devuelve el puntero para que sea compatible con char*
        (char*) transforma el dato a un array de char (byte)
        Ejemplo: Si data es un entero sizeof(int) es 4 bytes y &data es un int*
    */
    file.write((char*) &data, sizeof(T));
}

template<typename T>
void read(const char* name, T& data) { // data es un parámetro de salida
    ifstream file(name, ios::binary);
    file.read((char *) &data, sizeof(T));
}

int main () {
    // Escribir y leer un número entero
    int number = 7;
    write("binary", number);
    int number2;
    read("binary", number2);
    cout << number2 << endl;

    // Escribir y leer una clase
    Person person('R', 24);
    write("binary", person);
    Person person1(' ', 0);
    read("binary", person1);
    cout << person1.nameInitial << endl;
    cout << person1.age << endl;
}
