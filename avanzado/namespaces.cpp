#include <iostream>

namespace maths { // Declaración de un namespace
    namespace numeric { // Anidación de namespaces
        const double pi = 3.1416; // Variables y constantes en un namespace
        int sum (int a , int b) { // Funciones en un namespace
            return a + b;
        }
    }

    class Square { // Clases en un namespace
        float side;
    };
}

const double pi = 3.14; // Constante fuera del namespace con el mismo nombre

int main () {
    maths::Square square; // El operador :: sirve para acceder a un namespace
    std::cout << pi << '\n'; // Usa el único pi visible

    using namespace maths; // Ahora numeric y Square se pueden usar sin ::
    Square square2;

    int result = maths::numeric::sum(3, 5); // Acceso a namespaces anidados
    std::cout << result << '\n';

    // También se puede incluir un único elemento del namespace
    using maths::numeric::pi;
    std::cout << pi << '\n'; // Ambiguo, hay 2 constantes pi en este ámbito
    std::cout << maths::numeric::pi << '\n'; // Especificamos un pi

    // Alias: nuevo nombre para namespaces anidados
    namespace numbers = maths::numeric;
    std::cout << numbers::sum(6, 22) << '\n';
}
