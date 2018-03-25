#include <iostream>

int main() {
    std::hash<std::string> hasher;
    size_t secret = hasher("1234");

    std::string password;
    std::cout << "Introduzca la contraseña: ";
    std::cin >> password;

    if (secret == hasher(password)) {
        std::cout << "Acceso concedido: Contraseña correcta" << '\n';
    } else {
        std::cout << "Acceso denegado: Contraseña incorrecta" << '\n';
    }
}
