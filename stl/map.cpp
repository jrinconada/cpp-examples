#include <iostream>
#include <map> // map es una implementación de una tabla hash (acceso rápido a valores mediante la clave)

int main () {
    std::map<int, char> roman;

    // Insertar (También se puede usar la función insert)
    roman[1] = 'i';
    roman[5] = 'V';
    roman[10] = 'X';
    roman[50] = 'L';
    roman[100] = 'C';
    roman[200] = 'D';

    // Modificación
    roman[1] = 'I';

    // Borrado
    roman.erase(200);

    // Acceso (también se puede usar la función at)
    std::cout << "Nueve es: " << roman[1] << roman[10] << '\n';

    // Recorrer con iterador
    std::map<int, char>::iterator i; // Definición del iterador
    for (i = roman.begin(); i != roman.end(); i++) {
        std::cout << i->first << " es ";
        std::cout << i->second << '\n';
    }

    std::cout << roman.size() << '\n'; // Tamaño
    std::cout << roman.empty() << '\n'; // ¿Está vacío?
    roman.clear(); // Borrar todo
    std::cout << roman.size() << '\n'; // Tamaño
    std::cout << roman.empty() << '\n'; // ¿Y ahora?
}
