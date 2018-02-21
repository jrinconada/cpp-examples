#include <iostream>

/*
Stack: Las variables son creadas y destruidas dentro del ámbito definido por {}
Heap: Son creadas y destruidas de forma explícita con new / delete
Stack vs Heap:
    - En stack las variables se crean más rápido.
    - En stack no hay que preocuparse destruir variables.
    - Heap tiene más capacidad
    - Heap permite controlar la vida de las variables
*/

class Class {

};

int main() {
    // Tipos primitivos
    int integerStack = 2; // Entero en stack
    // Entero en heap (new devuelve un puntero a la memoria del entero)
    int* integerHeap = new int(3);
    // Libera la memoria que ocupa integerHeap (delete requiere un puntero)
    delete integerHeap;

    // Arrays
    float arrayStack[4]; // Array de 4 float en stack
    float* arrayHeap = new float[50]; // Array de 50 float en heap
    delete[] arrayHeap; // Para liberar memoria de un array se usa delete[]

    // Clases
    Class classStack; // Instanciación de clase en Stack
    Class* classHeap = new Class(); // Instanciación de clase en Heap
    delete classHeap; // Llama al destructor y libera la memoria que ocupa classHeap

} // Este cierre marca el final del ámbito de main borrando todas la variables en stack
