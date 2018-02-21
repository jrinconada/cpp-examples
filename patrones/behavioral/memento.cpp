#include <iostream>

class Memento {
    float balance;
public:
    Memento(float balance) : balance(balance) {}
    friend class Account; // Permitimos que Account acceda pero nadie más
};

class Account {
public:
    float balance;
    Account() {
        balance = 0;
    }
    Memento deposit(float amount) {
        balance += amount;
        return Memento(balance); // Se crea un recuerdo con el estado actual de la cuenta
    }
    // Reestablece la cuenta al estado que indique el memento que recibe
    void restore(Memento& memento) {
        balance = memento.balance;
    }
};

int main () {
    Account account;
    std::cout << "Dinero: " << account.balance << '\n';
    Memento m1 = account.deposit(100); // Se crea una "foto" de la cuenta con 100
    std::cout << "Dinero: " << account.balance << '\n';
    Memento m2 = account.deposit(50); // Se crea una "foto" de la cuenta con 150
    std::cout << "Dinero: " << account.balance << '\n';

    account.restore(m1); // Volver al estado después del primer depósito
    std::cout << "Dinero: " << account.balance << '\n';
}
