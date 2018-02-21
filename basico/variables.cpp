#include <iostream>

int globalVariable = 6; // Visible en todos los ficheros
static int staticVariable = 4; // Visible sólo en este fichero
// En otro fichero estará declarada como: int externVariable
extern int externVariable; // Referencia a una variable global de otro fichero

int main() {

    // TIPOS PRIMITIVOS
    int integer = 324; // 4 bytes o 8 bytes dependiendo del compilador
    short halfInteger = 2; // 2 bytes
    long doubleInteger = 46; // 8 bytes
    char letter = 'a'; // 1 byte
    // bool valores false o 0, true 1 o cualquier otro número
    bool boolean = true; // 1 bit en teoría, 1 byte en realidad
    float decimal = 2.5; // 4 bytes
    double doubleDecimal = 6.273; // 8 bytes
    const double PI = 3.1416; // Constante (no se puede modificar)

    // int va de aprox. -2000 millones a 2000 millones
    // unsigned int va de aprox. 0 a 4000 millones
    unsigned int unsignedInteger = 234234;

    // sizeof devuelve el tamaño de la variable en bytes
    std::cout << sizeof integer << '\n';

    // ENUMERADOS
    enum Day { // Se pueden igualar a cualquier valor o ninguno
        Lunes = 1, Tuesday, Wednesday, Thrusday, Friday
    };
    Day day = Tuesday;
    std::cout << "Hoy: " << day << '\n';

    // TYPEDEF
    /* Dar el nombre number al tipo int o definir un nuevo tipo o
    Definir un nuevo tipo de dato que se llama number y se comporta igual que int */
    typedef unsigned int positive;
    typedef const char* String;
    positive number = 2;
    String text = "Hola!";
    std::cout << number << '\n';
    std::cout << text << '\n';
}
