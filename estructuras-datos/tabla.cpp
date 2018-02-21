#include <iostream>
using namespace std;
/*
    Tabla (Tabla Hash) o Mapa, HashMap, HashTable, Diccionario
    Es una estructura de datos compuesata de una conjunto de entradas relacionadas
    Cada clave tiene un valor asociado
*/

struct Entry {
    int key;
    string value;
};

/*
    Ejemplo de tabla hash implementada con un array estático
    La función hash es el módulo (resto) de la clave con el tamaño de array
    En un ejemplo real sería una lista dinámmica y un función hash mucho más compleja
*/
struct Table {
    static const int SIZE = 10;
    Entry* table[SIZE];

    void init() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    void put(int key, string value) {
        int hash = hashFunction(key);
        // Colisión
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = hashFunction(hash + 1);
        }
        // Modificación
        if (table[hash] != NULL) {
            table[hash]->value = value;
        } else { // Nuevo elemento
            Entry* newEntry = new Entry;
            newEntry->key = key;
            newEntry->value = value;
            table[hash] = newEntry;
        }
    }

    string get(int key) {
        int hash = hashFunction(key);
        // Colisión
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = hashFunction(hash + 1);
        }
        // No existe un elemento con esa clave
        if (table[hash] == NULL) {
            return "";
        } else { // Encontrado
            return table[hash]->value;
        }
    }

    // Función hash, normalmente una función complicada con colisiones mínimas
    int hashFunction(int key) {
        return key % SIZE;
    }

    void print() {
        for (int i = 0; i < SIZE; i++) {
            if (table[i] != NULL) {
                cout << table[i]->key << " - ";
                cout << table[i]->value << endl;
            }
        }
        cout << "--------" << endl;
    }
};

int main() {
    Table table;
    table.init();
    table.put(3, "tres"); // Nuevo elemento
    table.print();
    table.put(5, "Cinco"); // Nuevo elemento
    table.print();
    table.put(3, "Tres"); // Modificación
    table.print();
    table.put(15, "Quince"); // Colisión
    table.print();
}
