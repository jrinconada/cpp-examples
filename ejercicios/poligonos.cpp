#include <iostream>

const float PI = 3.14;

struct Polygon {
    int sides;
    float length;

    float area() {
        if (sides == 0) {
            return length * length * PI;
        } else if (sides == 4){
            return length * length;
        }
    }
};

struct Square {
    float side;
    float area() {
        return side * side;
    }
};

struct Triangle {
    float base;
    float height;
    float area() {
        return (base * height) / 2
    }
};

void print(Polygon polygons[], int size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << "area: " << polygons[i].area() << '\n';
    }
}

int main () {
    Polygon cuadrado, circulo;

    // Crear cuadrado
    cuadrado.sides = 4;
    cuadrado.length = 10;

    // Crear círculo
    circulo.sides = 0;
    circulo.length = 3;

    Polygon polygons[2];
    polygons[0] = cuadrado;
    polygons[1] = circulo;

    int size = sizeof(polygons) / sizeof(Polygon);
    print(polygons, size);

}
