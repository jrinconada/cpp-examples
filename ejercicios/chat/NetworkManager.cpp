#include <iostream> // cout
#include <sys/socket.h> // sockaddr, socklen_t
#include <stdlib.h> // atoi
#include <netinet/in.h> // sockaddr_in
#include <string.h> // strlen
#include <unistd.h> // read, close
#include <arpa/inet.h> // inet_ntoa
#include "Message.cpp"
using namespace std;

class NetworkManager {
    static const int port = 8888;
    int sock;
public:
    bool init() {
        // Crear socket
        sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock < 0) return false;

        // Reutilizar IP y puerto
        int enable = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable))) {
            return false;
        }

        // Asignar IP y puerto
        struct sockaddr_in address;
        address.sin_family = AF_INET; // Address Family IPv4
        address.sin_addr.s_addr = INADDR_ANY; // IP de esta máquina
        address.sin_port = htons(port); // Puerto de Endian de Host a Endian de Network

        // Asociar IP y puerto al socket
        if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
            return false;
        }

        return true;
    }

    Message* revieve() {
        struct sockaddr_in address;
        const int bufferSize = 1024;
        char buffer[bufferSize] = {0};
        socklen_t addrlen = sizeof(address);

        // Recibir mensaje
        int n = recvfrom(sock, buffer, bufferSize, 0, (struct sockaddr *)&address, &addrlen);

        if (n > 0) {
            Message* m = new Message;
            m->text = buffer;
            m->user.address = address;
            return m;
        } else {
            return NULL;
        }
    }

    void send(Message* message) {
        struct sockaddr_in address = message->user.address;
        const char* m = "hola!!!!!";

        sendto(sock, m, strlen(m), 0, (struct sockaddr *)&address, sizeof(address));
    }

    void end() {
        close(sock);
    }
};
