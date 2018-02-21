#include <iostream>

/*
	Uso de declaración anticipada para poder hacer uso cíclico de las clases:
	A usa B que usa A
*/

// Declaración de B para que lo pueda usar A
struct B;

// Declaración de A con un método para que lo pueda usar B
struct A {
	void mA(B* b);
};

// Definición de B
struct B {
	void mB(A* a) {
		std::cout << "B llama a A" << '\n';
		a->mA(this);
	}
};

// Definición de función mA
void A::mA(B* b) {
	std::cout << "A llama a B" << '\n';
	b->mB(this);
}

int main () {
	A* a;
	B* b;
	a->mA(b);
}
