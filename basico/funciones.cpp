#include <iostream>
#include <math.h>
using namespace std;

/* Declaración de función:
    tipo_retorno nombre(tipo_parametro nombre_parametro);
void significa que no devuelve nada
char* puntero a caracteres (texto o string)
const no se puede modificar dentro de la función
Las declaraciones suelen estar en ficheros .h */
void print(const char* message);

// Sobrecarga de la función print
// (mismo nombre, distinto parámetro, número de parámetros o valor de retorno)
void print(int number);

// Declaración y definición en el mismo sitio (antes de usarse)
/*  inline: copia la función directamente el código
    Evita la reserva de memoria dinámica
    Pros: No se pierde tiempo en reservar memoria dinámicamente
    Cons: Si no se usa la función se ha reservado memoria innecesariamente
*/
inline void addOne() {
    // static dentro de una función hace que la variable actúe como global siendo local
    static int counter = 0;
    counter++;
    cout << counter << endl;
}

// exponent es un parámetro opcional, si no se especifica se usa el valor 2
float power(float base, float exponent = 2) {
    return pow(base, exponent); // pow es una funcón de math.h para hacer potencias
}

int main() {
    print("Hola");
    addOne();
    addOne();
    addOne();
    print(5);
    // La función power se puede llamar con uno o dos parámetros
    std::cout << power(2, 3) << '\n';
    std::cout << power(2) << '\n';
}

/* Definición de la función (cabecera y cuerpo)
Las definiciones suelen estar en ficheros .cpp */
void print(const char* message) {
    cout << message << endl;
}

void print(int number) {
    std::cout << number << '\n';
}
