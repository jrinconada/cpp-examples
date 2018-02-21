#include <iostream>

class Singleton {
private:
    Singleton() {}; // Constructor privado para evitar instanciaciones
    Singleton(const Singleton& s); // Constructor copia sin implementar
    void operator=(const Singleton& s); // Operador = sin implementar

public:
    int valor;
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void sayHello() {
        std::cout << "Hola, soy el Singleton" << '\n';
    }
};

int main() {
    Singleton::getInstance().sayHello();
    Singleton::getInstance().sayHello(); // Es siempre la misma instancia (no se vuelve a crear)
    Singleton::getInstance().valor = 4;
    Singleton::getInstance().valor = 5; // Misma instacia, misma variable valor
    std::cout << Singleton::getInstance().valor << '\n';
}
