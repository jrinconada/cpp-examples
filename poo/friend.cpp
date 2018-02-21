#include <iostream>

class Square {
    // Permite a Rectangle acceder a los miembros privados de Square
    friend class Rectangle;
private:
    int side;
public:
    Square(int s) : side(s) {}
};

class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() {
        return width * height;
    }
    // Transforma el rectángulo en un cuadrado con las dimensiones de square
    void squareIt(Square square) {
        width = square.side;
        height = square.side;
    }
    // Permite a la función display acceder a los miembros privados de Rectangle
    friend void display(Rectangle& rectangle);
};

void display(Rectangle& rectangle) {
    std::cout << "Ancho: " << rectangle.width << '\n';
    std::cout << "Alto: " << rectangle.height << '\n';
    std::cout << "Área: " << rectangle.area() << '\n';
}

int main() {
  Rectangle rectangle(3, 5);
  display(rectangle);
  
  Square square(4);
  rectangle.squareIt(square);
  display(rectangle);
}
