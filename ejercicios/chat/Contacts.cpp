#include "NetworkManager.cpp"
#include <vector>

struct Contacts {
    std::vector<User*> users;

    void add(Message* m) {
        string nick = m->getNick();
        if (get(nick) != NULL) return; // El usuario ya está guardado
        users.push_back(new User(nick, m->user.address));
    }

    User* get(string nick) {
        for (auto& u : users) {
            if (u->nick == nick) {
                return u;
            }
        }
        return NULL;
    }
};
