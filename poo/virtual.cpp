#include <iostream>

class Animal {
public:
    // Un método virtual se puede sobreescribir en las clases hijas
    // Si no se sobreescribe se utiliza el método del padre
    virtual void breathe() {
        std::cout << "Respirando..." << '\n';
    }

    // Método virtual puro (llamado abstracto o interfaz en otros lenguajes)
    // No tiene implementación, las clases hijas deben implementarlo
    // Animal es ahora una clase abstracta y por tanto no se puede instanciar
    virtual void makeNoise() = 0;
};

// Cat sobreescribe makeNoise (es obligatorio al heredar de Animal)
class Cat : virtual public Animal { // virtual: Resuelve el problema del diamante
public:
    void makeNoise() {
        std::cout << "Miau Miau" << '\n';
    }
};

// Fish sobreescribe makeNoise (obligatorio) y breathe para usar su funcionalidad
class Fish: virtual public Animal { // virtual: Resuelve el problema del diamante
public:
    void breathe() {
        std::cout << "Respirando con branquias..." << '\n';
    }
    void makeNoise() {
        std::cout << "Glub glub" << '\n';
    }
};

/*
    PROBLEMA DEL DIAMANTE: Ambiguedad al llamar a breathe (Animal o Fish)
    
      Animal
      /    \
    Cat   Fish
      \   /
     CatFish
*/
class CatFish: public Cat, public Fish {
public:
    void makeNoise() {
        std::cout << "Glub glub" << '\n';
    }
};

int main() {
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat();
    Fish* fish = new Fish();

    // Un array de Animales puede contener gatos o peces
    Animal* animals[3];
    animals[0] = cat1;
    animals[1] = cat2;
    animals[2] = fish;

    for (size_t i = 0; i < 3; i++) {
        animals[i]->breathe(); // Cada Animal respira de una manera
        animals[i]->makeNoise(); // Cada Animal hace un ruido propio
    }

    // Problema de diamante
    CatFish* catFish = new CatFish();
    // Llamada ambígua: Animal y Fish tienen el método breathe
    // Solución: usar virtual al heredar Animal
    catFish->breathe();
}
