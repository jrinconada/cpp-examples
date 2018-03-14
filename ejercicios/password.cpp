#include <iostream>
#include <cstring>

bool areEquals (const char pass1[], const char pass2[]) {
    return strcmp(pass1, pass2) == 0;
}

int main() {
    const int max = 5;
    const char pass[] = "123"; // C style

    std::string userPass;
    int fails = 0;
    do {
        std::cout << "Contraseña: ";
        std::cin >> userPass;

        /*
            userPass            es std::string
            pass                es char*
            userPass.c_str()    es const char*
        */
        if (!areEquals(pass, userPass.c_str())) {
            std::cout << "Contraseña incorrecta" << '\n';
            fails++; // fails = fails + 1;
        } else {
            std::cout << "Contraseña correcta" << '\n';
        }
    } while(!areEquals(pass, userPass.c_str()) && (fails < max));
    // son distintas y no hemos llegado al numero de intentos

    if (fails == max) {
        std::cout << "Acceso denegado" << '\n';
    }
}
