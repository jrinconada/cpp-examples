#include <iostream>

struct Node {
    int data;
    Node* next;
};

/*
    Lista: Estructura de datos que permite uso como LIFO (Pila) y FIFO (Cola)
    Implementación con una lista enlazada
    Orden de complejidad 1 para todas las operaciones excepto quitar el último
*/
struct List {
    Node* first;
    Node* last;

    void init() {
        first = NULL;
        last = NULL;
    }

    void add(int value) { // Añadir al final
        Node* newNode = new Node; // Crear nuevo nodo
        newNode->data = value; // Añadir el valor
        newNode->next = NULL; // Es el último por lo que no tiene siguiente
        if (first != NULL) { // Caso normal: la lista no está vacía
            last->next = newNode;
            last = newNode;
        } else { // Caso especial: la lista está vacía
            first = newNode;
            last = newNode;
        }
    }

    void push(int value) { // Poner al principio
        Node* newNode = new Node; // Crear nuevo nodo
        newNode->data = value; // Añadir el valor
        newNode->next = first; // Apuntar al primer elemento de la lista
        first = newNode; // El nuevo elemento para a ser el primer elemento
        if (last == NULL) { // Si la lista estaba vacía el primero es el último
            last = newNode;
        }
    }

    void removeFirst() {
        if (first == NULL) return; // Si no hay elementos no se hace nada

        Node* temp = first; // Hay que guardar el primer elemento para no perderlo
        first = first->next; // El segundo elemento pasa a ser el primero
        delete temp; // Se libera la memoria del primer elemento
        // Si se ha borrado el último / único  elemento que quedaba
        if (first == NULL) {
            last = NULL;
        }
    }

    // Hay que recorrer la lista para obtener el penúltimo elemento: O(n)
    void removeLast() {
        if (last == NULL) return; // Si no hay elementos no se hace nada

        Node* current = first;
        Node* previous = NULL;
        while (current->next != NULL) { // Avanzar hasta llegar al último
            previous = current;
            current = current->next;
        }
        last = previous; // El anterior al último pasa a ser el último
        if(last != NULL) { // Al borrar el último elemento no hay previous
            last->next = NULL;
        }
        delete current; // Liberar memoria del elemento a borrar
    }

    void print() {
        Node* aux = first; // Puntero auxiliar para recorrer todos los elementos
        while (aux != NULL) { // Hasta el último que no apunta a nada
            std::cout << aux->data << '\n';
            aux = aux->next;
        }
        std::cout << "--------" << '\n';
    }
};

int main() {
    List list;
    list.init();
    list.push(5);
    list.print();
    list.push(45);
    list.print();
    list.push(12);
    list.print();
    list.removeLast();
    list.print();
    list.removeLast();
    list.print();
    list.removeLast();
    list.print();
    list.removeLast();
    list.print();
}
