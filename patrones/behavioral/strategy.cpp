#include <iostream>
#include <vector>

// Es una forma de actuar que todos los hijos deben cumplir
struct BillStrategy {
    virtual float applyDiscount(float total) = 0;
    virtual void printBye() = 0;
};

struct StandardStrategy : public BillStrategy {
    float applyDiscount(float total) {
        return total; // Sin descuento
    }

    void printBye() {
        std::cout << "Gracias por su visita" << '\n';
    }
};

struct HappyHourStrategy : public BillStrategy {
    float applyDiscount(float total) {
        return total * 0.5; // 50% de descuento
    }

    void printBye() {
        std::cout << "No olvide pedir un taxi para volver a casa" << '\n';
    }
};

class Bill {
    std::vector<float> orders;
    float total;
    BillStrategy* strategy;

    void calculateTotal() {
        total = 0;
        for (size_t i = 0; i < orders.size(); i++) {
            total += orders[i];
        }
    }

    void printBill() {
        for (size_t i = 0; i < orders.size(); i++) {
            std::cout << "Producto " << i << ": " << orders[i] << '\n';
        }
        std::cout << "Total: " << total << '\n';
        std::cout << "---------------" << '\n';
    }

public:
    Bill(BillStrategy* strategy) {
        this->strategy = strategy;
    }

    void order(float amount) {
        orders.push_back(amount);
    }

    void print() {
        calculateTotal();
        total = strategy->applyDiscount(total);
        printBill();
        strategy->printBye();
        std::cout << "- - - - - - -" << '\n';
    }
};

int main() {
    Bill standardBill(new StandardStrategy); // Se define un comportamiento en tiepo de ejecución
    standardBill.order(3.5);
    standardBill.order(5.4);
    standardBill.print();
    Bill happyHourBill(new HappyHourStrategy);
    happyHourBill.order(4);
    happyHourBill.order(4);
    happyHourBill.order(4);
    happyHourBill.order(2.2);
    happyHourBill.order(3.5);
    happyHourBill.print();
}
