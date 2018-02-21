#include <iostream>

struct Node {
    int data;
    Node* next;
};

/*
    Pila: Estructura de datos LIFO (Last In Last Out)
    Implementación con una lista enlazada
    Orden de complejidad 1 para todas las operaciones
*/
struct Stack {
    Node* first;

    void init() {
        first = NULL;
    }

    void push(int value) { // Poner al principio
        Node* newNode = new Node; // Crear nuevo nodo
        newNode->data = value; // Añadir el valor
        newNode->next = first; // Apuntar al primer elemento de la lista
        first = newNode; // El nuevo elemento para a ser el primer elemento
    }

    int pop() { // Sacar el primero
        if (first == NULL) return -1; // Si no hay elementos se devuelve -1 y no se hace nada más

        Node* temp = first; // Hay que guardar el primer elemento para no perderlo
        first = first->next; // El segundo elemento pasa a ser el primero
        int value = temp->data; // Se guarda el valor del elemento que borrarmos
        delete temp; // Se libera la memoria del primer elemento
        return value;
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
    Stack stack;
    stack.init();
    stack.push(5);
    stack.print();
    stack.push(45);
    stack.print();
    stack.push(12);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
}
