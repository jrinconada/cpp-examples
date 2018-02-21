#include <iostream>
#include <sstream>
using namespace std;

int main () {
    // Formateo de strings sin operación de entrada / salida
    // Útil si se quiere hacer en dos pasos por eficiencia
    // Se pueden usar todos los manipuladores de fstream y iomainp
    stringstream ss;

    // Formateo
    ss << 20 << " en hex: " << hex << 20; // 20 en base hexadecimal (base 16)
    // Escritura por consola
    cout << ss.str() << '\n';

    // Lectura
    int number;
    ss >> dec >> number; // Leer en base decimal
    string s; // Leer string
    ss >> s;
    ss.ignore(5); // Saltar los siguientes 4 caracteres
    string hexNumber;
    ss >> hexNumber; // Leer el número como un string

    std::cout << number << '\n';
    std::cout << s << '\n';
    std::cout << hexNumber << '\n';
}
