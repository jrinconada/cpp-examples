#include "User.cpp"
using namespace std;

struct Message {
    string text;
    User user;

    string getMessage() {
        string m = "";
        bool found = false;
        for (size_t i = 0; i < text.size(); i++) {
            if (found) m += text[i];
            if (text[i] == '>') {
                found = true;
            }
        }
        return m;
    }

    string getNick() {
        string n = "";
        for (size_t i = 0; i < text.size(); i++) {
            if (text[i] == '>') break;
            n += text[i];
        }
        return n;
    }
};
