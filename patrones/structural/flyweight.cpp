#include <iostream>
#include <map>

using namespace std;

class User {
    static long id;
    long nameId;
public:
    User(string name) {
        id++;
        nameId = store(name);
    }

    string getName() {
        return names[nameId]; // devuelve el nombre para la clave almacenada
    }

    static long nameIdCount;
    static map<long, string> names;
    static map<string, long> ids;

    static long store (string name) {
        auto iterator = ids.find(name);
        if (iterator == ids.end()) { // Si no está en el mapa
            names[nameIdCount] = name; // Se inserta el nombre con el id actual
            ids[name] = nameIdCount; // Se inserta el id con el nombre actual
            return nameIdCount++;
        }
        return iterator->second; // Si está en el mapa se devuelve el id
    }
};
// Definiciones de variables estáticas
long User::id = 0;
long User::nameIdCount = 0;
map<long, string> User::names;
map<string, long> User::ids;

// Función para imprimir un mapa y ver si todo está correcto
template <typename L, typename S>
void print(map<L, S> m) {
    for (auto i = m.begin(); i != m.end(); i++) {
        std::cout << i->first << " es ";
        std::cout << i->second << '\n';
    }
}

int main () {
    User pepe("Pepe");
    User ivan("Iván");
    User pepe2("Pepe");


    std::cout << pepe.getName() << '\n';
    std::cout << ivan.getName() << '\n';
    std::cout << pepe2.getName() << '\n';
    print(User::names);
}
