#include <iostream>

class Implementation {
public:
    virtual void doSomething() = 0;
};

// Clase instanciable que recibe una implemanción dependiente de la plataforma
class ConcreteClass {
    Implementation* implementation;
public:
    ConcreteClass(Implementation* i) {
        implementation = i;
    }

    void doSomething() { // En realidad no hace nada, lo hace implementation
        implementation->doSomething();
    }
};

// Implementación dependiente de la plataforma para Windows
class WindowsImplementation : public Implementation {
public:
    void doSomething() {
        std::cout << "Implementación concreta de Windows" << '\n';
    }
};

// Implementación para Linux
class LinuxImplementation : public Implementation {
public:
    void doSomething() {
        std::cout << "Implementación concreta de Linux" << '\n';
    }
};

int main () {
    WindowsImplementation* win = new WindowsImplementation;
    LinuxImplementation* lin = new LinuxImplementation;

    ConcreteClass concreteForWindows(win);
    ConcreteClass concreteForLinux(lin);

    concreteForWindows.doSomething();
    concreteForLinux.doSomething();
}
