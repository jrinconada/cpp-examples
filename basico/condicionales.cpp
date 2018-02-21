#include <iostream>

int main() {
    int age = 100;

    if(age < 18) {
        std::cout << "Niño" << '\n';
    } else if(age == 18) {
        std::cout << "Joven adulto" << '\n';
    } else if(age > 18 && age <= 65) {
        std::cout << "Adulto" << '\n';
    } else {
        if (age > 99) {
            std::cout << "Muy ";
        }
        std::cout << "Anciano" << '\n';
    }

    switch (age) {
        case 18:
        std::cout << "Tu primer año de vida adulta" << '\n';
        break; // break impide que se evalúen más condiciones
        case 65:
        case 99:
        case 100:
        std::cout << "¿Qué hay de nuevo viejo?" << '\n';
        break;
        default: // Si no se ha cumplido niguna condición (o no se ha hecho break)
        std::cout << "Buenos días" << '\n';
    }

    // Operador ternario
    int people = 1;
    std::string count = people > 1 ? "Varios" : "Uno";
    std::cout << count << '\n';
    // if equivalente al operador ternario anterior
    std::string count2;
    if (people > 1) {
        count2 = "Varios";
    } else {
        count2 = "Uno";
    }
}
