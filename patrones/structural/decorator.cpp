#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Soy un círculo";
    }
};

// Añadir funcionalidad a Circle sin modificar la clase
class ColoredShape : public Shape {
public:
    Shape& shape;
    string color;

    // Se obtine una Shape en el construtor
    ColoredShape(Shape& s, const string c) : shape(s), color(c) {}

    // Se llama la función correspondiente de Circle y se añade la funcionalidad
    void draw() {
        shape.draw();
        std::cout << " de color " << color << '\n';
    }
};

int main () {
    Circle circle;
    circle.draw();
    std::cout << '\n';

    ColoredShape redCircle(circle, "rojo");
    redCircle.draw();
}
