#include <iostream>

// Una clase que requiere rellenar muchos parámetros con valores concretos
class Printer {
    int pageSize;
    bool color;
    std::string docType;
    std::string text;
public:
    bool setSize(int size) {
        if (size > 0 && size < 30) {
            pageSize = size;
            return true;
        } else {
            return false;
        }
    }

    void setColor(bool inColor) {
        color = inColor;
    }

    bool setDocType(std::string type) {
        if (type == std::string(".txt") ||
        type == std::string(".pdf") ||
        type == std::string(".doc")) {
            docType = type;
            return true;
        } else {
            return false;
        }
    }

    void setText(std::string t) {
        text = t;
    }

    bool print() { // Función que requiere haber inicializado muchas cosas
        if (docType == std::string(".txt") ||
        docType == std::string(".pdf") ||
        docType == std::string(".doc")) {
            if (pageSize > 0 && pageSize < 30) {
                if (text != "") {
                    std::cout << text << '\n';
                    return true;
                }
            }
        }
        return false;
    }

};

// Simplificación de impresora
class Facade {
    Printer printer;
public:
    void print(std::string text) {
        printer.setSize(20);
        printer.setColor(true);
        printer.setDocType(".pdf");
        printer.setText(text);
        printer.print();
    }
};

int main () {
    Facade printer;
    printer.print("Hola que tal");
}
