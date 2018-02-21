#include <iostream>
#include <sstream>

struct Expression {
    // Es necesario declarar algo para que la clase pueda ser usada
    virtual ~Expression() = default;
};

struct Number : Expression {
    double value;
    Number(double value) : value(value) {}
};

struct Addition : Expression {
    Expression *left;
    Expression *right;
    Addition(Expression* left, Expression* right) : left(left), right(right) {}
};

struct ExpressionPrinter {
    std::ostringstream printable;
    void createPrintable(Expression* e) {
        if (auto number = dynamic_cast<Number*>(e)) {
            printable << number->value;
        } else if (auto addition = dynamic_cast<Addition*>(e)) {
            createPrintable(addition->left);
            printable << " + ";
            createPrintable(addition->right);
        }
    }
};

int main() {
    Expression* e = new Addition(new Number(23),
        new Addition(new Number(74), new Number(55)));
    ExpressionPrinter printer;
    printer.createPrintable(e);
    std::cout << printer.printable.str() << '\n';
}
