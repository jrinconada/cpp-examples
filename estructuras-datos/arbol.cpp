#include <iostream>

struct Node {
    int data;
    Node* left; // Hojas menores o iguales a esta
    Node* right; // Hojas mayores a esta
};

/*
    Árbol binario: Estructura de datos pensada para búsquedas
    Orden de complejidad Log(n) de media en inserciones y búsquedas
*/
struct Tree {
    Node* root;

    void init() {
        root = NULL;
    }

    void insert(int value) {
        insert(value, root); // Se llama a insertar con la raiz
    }

    void insert(int value, Node*& node) {
        if (node == NULL) { // Si se ha llegado aquí es que es un nodo hoja
            std::cout << "hoja" << '\n';
            Node* newLeaf = new Node;
            newLeaf->data = value;
            newLeaf->left = NULL;
            newLeaf->right = NULL;
            node = newLeaf;
        } else if (node->data > value) { // Si este nodo es mayor que el valor
            std::cout << "a la izquierda" << '\n';
            insert(value, node->left); // Se intenta insertar a la izquierda
        } else { // Si este nodo es menor que el valor
            std::cout << "a la derecha" << '\n';
            insert(value, node->right); // Se intenta insertar a la derecha
        }
    }

    void search(int value) {
        search(value, root);
    }

    void search(int value, Node* node) {
        if (node == NULL) {
            std::cout << "No encontrado" << '\n';
        } else if (node->data == value) {
            std::cout << "Encontrado" << '\n';
        } else if (node->data > value) { // Si es mayor está a la izquierda
            std::cout << "a la izquierda de " << node->data << '\n';
            search(value, node->left);
        } else { // Si es menor o igual está a la derecha
            std::cout << "a la derecha de " << node->data << '\n';
            search(value, node->right);
        }
    }
};

int main() {
    Tree tree;
    tree.init();
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    tree.insert(0);
    tree.insert(1); // Se podría evitar que se inserten repetidos o sustituir el valor
    std::cout << "Búsqueda" << '\n';
    tree.search(0);
}
