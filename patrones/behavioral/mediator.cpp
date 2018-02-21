#include <iostream>
#include <vector>
using namespace std;

class User;

class Mediator {
    std::vector<User*> users;
public:
    void join (User* user);

    void send (string message, string name);
};

class User {
    std::vector<string> messages;
    Mediator* mediator;
public:
    string name;
    User (Mediator* m, string n) {
        mediator = m;
        name = n;
    }

    void say (string message) {
        mediator->send(message, name);
    }

    void recieve (string message) {
        std::cout << name << " recibido: " << message << '\n';
        messages.push_back(message);
    }
};

void Mediator::join (User* user) {
    users.push_back(user);
}

void Mediator::send (string message, string name) {
    std::cout << name << " dice: " << message << '\n';
    for (auto& user: users) {
        if (user->name != name) {
            user->recieve(message);
        }
    }
}

int main () {
    Mediator* chat = new Mediator;

    User* pepe = new User(chat, "pepe18");
    chat->join(pepe);

    User* luis = new User(chat, "luisito99");
    chat->join(luis);

    User* marta = new User(chat, "martaloca");
    chat->join(marta);

    pepe->say(string("Hola!"));
    luis->say(string("Holita!"));
    marta->say(string("Saludos"));
}
