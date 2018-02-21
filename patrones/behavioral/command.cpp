#include <iostream>
#include <vector>

// Una cuenta bancaria con las operaciones de meter y sacer dinero
class Account {
public:
    float balance;
    Account() {
        balance = 0;
    }
    void deposit(float amount) {
        balance += amount;
    }
    void withdraw(float amount) {
        balance -= amount;
    }
};

class Command {
    Account& account;
    short operation;
    int amount;
public:
    Command(Account& a, short o, int am) : account(a), operation(o), amount(am) {}

    void execute() {
        switch (operation) {
            case 1:
                account.deposit(amount);
            break;
            case 2:
                account.withdraw(amount);
            break;
            default:
                std::cout << "Operación inválida" << '\n';
        }
    }

    void undo() {
        switch (operation) {
            case 1:
                account.withdraw(amount);
            break;
            case 2:
                account.deposit(amount);
            break;
            default:
                std::cout << "Operación inválida" << '\n';
        }
    }
};

int main() {
    Account account = Account();
    std::vector<Command> commands;
    commands.push_back(Command {account, 1, 200});
    commands.push_back(Command {account, 2, 50});
    commands.push_back(Command {account, 2, 20});

    std::cout << "Balance: " << account.balance << '\n';
    for (auto& command : commands) {
        command.execute();
        std::cout << "Balance: " << account.balance << '\n';
    }

    commands[1].undo();
    std::cout << "Balance: " << account.balance << '\n';
}
