#include <iostream>

// struct es como una clase pero todo public por defecto y compatible con C
struct Rectangle {
    double height;
    double width;

    double area() {
        return height * width;
    }
};

// En una union la memoria es compatida, sólo contendrá un dato a la vez
// Útil para ahorrar memoria
union Data {
    char letter;
    double number;
    int counter;
};

int main() {
    // STRUCT
    Rectangle rectangle;
    rectangle.height = 3;
    rectangle.width = 5;
    std::cout << "Área: " << rectangle.area() << '\n';

    // UNION
    Data data;
    data.number = 287.347; // Sólo number está inicializado
    std::cout << data.letter << data.number << data.counter << '\n';
    data.letter = 'c'; // Se sobreescribe number, puede que sea ilegible
    std::cout << data.letter << data.number << data.counter << '\n';
    data.counter = 10; // Puede que number y letter sean ilegibles
    std::cout << data.letter << data.number << data.counter << '\n';
}
