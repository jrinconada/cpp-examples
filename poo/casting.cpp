#include <iostream>
#include <typeinfo>
#include <stdlib.h>

class Father {
    virtual ~Father() = 0; // Virtual puro
};
class Son: public Father {};

class Dog {};

int main() {
    // Casting implicito con posible pédida de información
    double decimal = 76.34;
    int integer = decimal;  // Pérdida de información
    decimal = integer; // Sin pérdida de información
    std::cout << integer << '\n';

    // Casting explícito
    integer = (int) decimal; // Notación estilo C
    integer = int(decimal); // Notación funcional
    std::cout << integer << '\n';

    // Transformar un string numérico a un número
    // atoi: int, atol: long, atof: double
    std::string numericText = "5";
    std::cout << atoi(numericText.c_str()) << '\n';

    // Casting dinámico: Sólo con punteros a objetos asegurando compatibilidad
    Father* father;
    Son* son;
    // De clase hijo a padre conversión con posible pérdida de información
    father = dynamic_cast<Father*>(son);
    // De clase padre a hijo (permitido sólo si padre es virtual puro)
    son = dynamic_cast<Son*>(father);

    // Casting estático: Con clases relacionadas sin comprobación de compatibilidad
    Dog* dog;
    //father = static_cast<Father*>(dog); // No están relacionadas: error en tiempo de compilación
    father = static_cast<Father*>(son); // De clase hijo a padre: permitido
    son = static_cast<Son*>(father); // De clase padre a hijo: permitido

    // Casting de reinterpretación de tipo: Sin ninguna comprobación (copia binaria)
    father = reinterpret_cast<Father*>(dog);

    // Casting de const: De constante a variable y de variable a constante
    const char* constante;
    char* variable;
    constante = const_cast<const char*>(variable); // No tiene uso real
    variable = const_cast<char*>(constante); // Para poder hacer: variable = constante;

    // typeid: Detección del tipo de dato
    std::cout << typeid(decimal).name() << '\n';
    std::cout << typeid(integer).name() << '\n';
    std::cout << typeid(father).name() << '\n';
    Dog dog2;
    std::cout << typeid(dog2).name() << '\n';
    std::cout << typeid(2.56).name() << '\n';
    if (typeid(integer) == typeid(2)) {
        std::cout << "Es un entero" << '\n';
    }
    if (typeid(father) == typeid(son)) {
        std::cout << "Son del mismo tipo" << '\n';
    } else {
        std::cout << "No son del mismo tipo" << '\n';
    }
}
