#include <iostream>

int main() {
    std::string text = "Hola"; // Definición
    text += " que tal"; // Concatenación

    std::cout << text << '\n';

    std::cout << text.length() << '\n'; // Longitud
    std::cout << text.find("tal") << '\n'; // Encontrar texto
    std::cout << text.substr(0, 4) << '\n'; // Obtener substring
    std::cout << text.erase(0, 5) << '\n'; // Borrar substring

    // De const char* a std::string
    const char* string_c = "String estilo C";
    std::string stringCpp(string_c);
    std::cout << stringCpp << '\n';
    // De std::string a const char*
    const char* string_c2 = text.c_str();
    std::cout << string_c2 << '\n';
}
