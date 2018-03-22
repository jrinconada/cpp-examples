static const int port = 8888;
#include "Contacts.cpp"
#include <thread>

Contacts contacts;
string myNick;

string getMessage() {
    string message;
    std::cout << myNick + " dice ";
    getline(cin, message);
    return message;
}

string getNick() {
    string nick;
    std::cout << "¿Nick o IP? (t para enviar a todos) ";
    getline(cin, nick);
    return nick;
}

void sendToAll(NetworkManager* nm, Message* message) {
    message->text = myNick + ">" + message->text;
    for (auto& u : contacts.users) {
        message->user = *u;
        nm->send(message);
    }
}

void send(NetworkManager* nm, Message* message, string detination) {
    message->text = myNick + ">" + message->text; // Enviar a uno

    User* u = contacts.get(detination);
    if (u == NULL) {
        u = new User;
        if (!u->setIP(detination)) {
            std::cerr << "Usuario o IP inválida" << '\n';
            return;
        }
    }
    message->user = *u;
    nm->send(message);
}

void receiving(NetworkManager* nm) {
    while(true) {
        Message* message = nm->recieve();
        contacts.add(message);
        std::cout << '\n' << message->getNick() << " dice " << message->getMessage() << '\n';
        std::cout << myNick + " dice " << std::flush;
    }
}

void emitting(NetworkManager* nm) {
    Message* message = new Message;
    while (true) {
        message->text = getMessage();

        if(message->text == "s") break;
        string nick = getNick();
        if(nick == "t") {
            sendToAll(nm, message); // Enviar a todos
        } else {
            send(nm, message, nick); // Enviar a uno
        }

    }
    terminate();
}

int main(int argc, char const *argv[]) {
    // Nick
    if(argc == 2) {
        myNick = argv[1];
    } else {
        std::cout << "Dime tu nombre:" << '\n';
        getline(cin, myNick);
    }

    // Inicialización
    NetworkManager* nm = new NetworkManager;
    if (!nm->init()) {
        std::cout << "Error de conexión" << '\n';
        return -1;
    }
    std::cout << "Hola " << myNick << ", bienvenido al Chat P2P" << '\n';
    std::cout << "(introduce s para salir)" << '\n';

    thread receiver(receiving, nm);

    emitting(nm);

    receiver.join();
    // Finalización
    nm->end();
}
