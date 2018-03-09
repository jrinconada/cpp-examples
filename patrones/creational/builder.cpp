#include <iostream>
using namespace std;

class Product {
    int i;
	float f;
	char c;
public:
    class Builder; // Clase par contruir Product

    void print(){
        cout << "i: " << this->i << " ";
        cout << "f: " << this->f << " ";
        cout << "c: " << this->c << endl;
    }
private:
	// Constructor con todas los parámetros necesarios
	Product(int i, float f, char c) : i(i), f(f), c(c){}
};

// Implementación de la clase constructora
class Product::Builder {
private:
	// variables needed for construction of object of Product class
	int i;
	float f;
	char c;

public:
	// Valores por defecto
	static const int defaultI = 1;
	static const float defaultF = 2.0f;
	static const char defaultC = '3';

	// Constructor por defecto
	Builder() : i(defaultI), f(defaultF), c(defaultC) {}

	/*    Funciones para valores personalizados
	      Devuelven el objeto para conveniencia de uso */
	Builder& setI(int i) {
        this->i = i;
        return *this;
    }

	Builder& setF(float f) {
        this->f = f;
        return *this;
    }

	Builder& setC(char c) {
        this->c = c;
        return *this;
    }

	// Devulve el producto construido
	Product build() {
		// Este sería un buen sitio para comprobar si la variables con apropiadas entre si
		return Product(this->i, this->f, this->c); // Constructor final
	}
};

int main(){
    // Construción en línea
	Product p1 = Product::Builder().setI(45).setF(3.5).setC('x').build();
	p1.print();

	Product::Builder b; // Constructor por defecto
	Product p2 = b.build(); // Objeto por defecto

    b.setC('!'); // Personalización del objeto por defecto
	Product p3 = b.build(); // Nuevo objeto semi personalizado

	p2.print();
	p3.print();
}
