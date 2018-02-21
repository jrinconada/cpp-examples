#include <iostream>

class Vector {
public:
    float x, y;
    Vector(float x, float y) {
        this->x = x;
        this->y = y;
    }
    // Sobreescritura del operador +
    Vector operator+(const Vector& v) {
        return Vector(x + v.x, y + v.y);
    }

    std::string toString() {
        return std::string("x " + std::to_string(x) + ", y " + std::to_string(y));
    }

    // Sobreescritura del operador ==
    bool operator==(const Vector& v) {
        return x == v.x && y == v.y;
    }

    // Sobreescritura del operador << para poder imprimir por consola facilmente
    friend std::ostream& operator<<(std::ostream &os, const Vector& v) {
        os << "x: " << v.x << " y: " << v.y;
        return os;
    }
};

int main() {
    Vector v1(3, 4);
    Vector v2(5, 6);
    Vector v3 = v1 + v2;

    std::cout << "v1: " << v1 <<'\n';
    std::cout << "v2: " << v2 <<'\n';
    std::cout << "v3: " << v3 <<'\n';

    if (v1 == v2) {
        std::cout << "Iguales" << '\n';
    } else {
        std::cout << "Distintos" << '\n';
    }
}
