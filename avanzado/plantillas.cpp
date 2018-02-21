#include <iostream>
#include <math.h>

/*  Función genérica
    template indica que se va a crear una platilla
    typename define el nombre del tipo de dato T
    T se cambia en tiempo de ejecución por un tipo de dato concreto
    El código de la función se genera en tiempo de ejecución */
template <typename T> // También se podría escribir así: template <class T>
void print (T value) {
    std::cout << value << '\n';
}

// Parámetros del mismo tipo
template <typename N>
void sum (N a, N b) {
    N result = a + b;
    std::cout << "Suma: " << result << '\n';
}

// Parámetros de distinto tipo
template <typename B, typename E>
void power (B base, E exponent) {
    std::cout << "Potencia: " << pow(base, exponent) << '\n';
}

// Especialización con template
template <>
void sum (char a, char b) {
    std::cout << "No se pueden sumar letras" << '\n';
}

// Especialización parcial
template <typename N>
void power (N base, unsigned int exponent) {
    std::cout << "Potencia con exponente positivo: " << pow(base, exponent) << '\n';
}

/*  Clase genérica
    Se pueden declarar varios datos en un template
    Se puede especificar el tipo de cada dato
    MyArray permite usar una variable interna para saber el número de elementos */
template<typename T, int N>
class MyArray {
private:
    T data[N]; // El tipo de dato y el número de elementos se definen en tiempo de ejecución
public:
    int size() const {
        return N; // Este array si permite saber el número de elementos
    }
};

int main () {
    print(5);
    print("hola");
    print<float>(845.2); // Se puede especificar el tipo de dato
    print<char>('u');

    power(2, 3.2);
    sum(33, 45);
    sum(2.3, 8.2);
    sum('d', 'e');
    unsigned int exponent = 3;
    power(4, exponent);

    MyArray<double, 10> myArray;
    std::cout << myArray.size() << '\n';
}
