using namespace std;

struct User {
    string nick;
    struct sockaddr_in address;
    string ip;

    User() {}

    User(string n, struct sockaddr_in a) : nick(n), address(a) {}

    bool setIP(string ip) {
        memset(&address, '0', sizeof(address));
        address.sin_family = AF_INET;
        address.sin_port = htons(port);

        if(inet_aton(ip.c_str(), &address.sin_addr) <= 0) {
            return false;
        }
        return true;
    }
};
