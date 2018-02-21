#include <iostream>

// Hay una clase cuadrado pero mi programa sólo puede trabajar con rectangulos
class Square {
public:
    float side;
    Square (int s) : side(s) {}
};

class Rectangle {
public:
    float width;
    float height;
};

// Tranforma un cuadrado en un rectángulo
class RectangleAdapter : public Rectangle {
public:
    RectangleAdapter (Square square) {
        width = square.side;
        height = square.side;
    }
};

int main () {
    Square square(6); // Cuadrado de 6x6

    Rectangle rectangle;
    // Se usa el adapter para crear un rectángulo a partir de un cuadrado
    rectangle = RectangleAdapter(square);
    
    std::cout << "w: " << rectangle.width << " h: " << rectangle.height <<'\n';
}
