#include <iostream>
#include <typeinfo>

/*
    Excepción propia: throw
*/
int division (int numerator, int denominator) {
    if (denominator ==  0) {
        throw "división por 0"; // Se lanza una excepción (salto al catch)
    }
    return numerator / denominator;
}

void inputDivision() {
    int numerator, denominator, result;
    std::cout << "Numerador: ";
    std::cin >> numerator;
    std::cout << "Denominador: ";
    std::cin >> denominator;

    try { // Dentro del bloque try se puden lanzar excepciones
        result = division(numerator, denominator);
    } catch (const char* message) { // Se recibe un dato (puede ser de cualquier tipo)
        // Se gestiona el error (salida por consola de error)
        std::cerr << "Error: " << message << '\n';
        result = 0;
    }

    std::cout << "Resultado: " << result << '\n';
}

/*
    Excepción de librería std
*/
// Clases padre e hijo para probar la excepción de casting
class Base {
    virtual void someFunction() {}
};
class Derived : Base {};

void casting () {
    // Un casting dinámico de padre a hijo produce una excepción
    Base base;
    Derived& derived = dynamic_cast<Derived&>(base);
}

void castingWithErrorChecking () {
    // Se captura la excepción del casting dinámico
    try {
        Base base;
        Derived& derived = dynamic_cast<Derived&>(base);
    } catch (std::bad_cast& e) {
        // La función what devuelve el mensaje de la excepción
        std::cerr << "Error: " << e.what() << '\n';
    }
}

int main () {
    inputDivision(); // División entera

    castingWithErrorChecking(); // Excepción controlada: El programa continúa

    casting(); // Excepción no controlada: El programa se para

    std::cout << "Fin." << '\n';
}
