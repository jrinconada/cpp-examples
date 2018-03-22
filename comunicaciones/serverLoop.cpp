#include <iostream> // cout
#include <sys/socket.h> // sockaddr, socklen_t
#include <stdlib.h> // atoi
#include <netinet/in.h> // sockaddr_in
#include <string.h> // strlen
#include <unistd.h> // read, close
#include <arpa/inet.h> // inet_ntoa
#include <thread>
#include <vector>
using namespace std;


void connection(int commSocket) {
    const int bufferSize = 1024;

    while(true) {
        char buffer[bufferSize] = {0};

        while(recv(commSocket, buffer, sizeof(buffer), 0) <= 0);

        std::cout << "Mensaje recibido: " << buffer << '\n';

        const char *message = "Hola, estoy aquí para servirte";
        send(commSocket, message, strlen(message), 0);
    }
}

int main(int argc, char const *argv[]) {

    int port = 8888;
    if (argc > 1) {
        port = atoi(argv[2]);
    }

    int listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listeningSocket < 0) {
        std::cerr << "Error: creación de socket" << '\n';
        return -1;
    }

    int enable = 1;

    if (setsockopt(listeningSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable))) {
        std::cerr << "Error: puerto en uso" << '\n';
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET; // Address Family IPv4
    address.sin_addr.s_addr = INADDR_ANY; // IP 0.0.0.0 (todas las interfaces de red)
    address.sin_port = htons(port); // Puerto de Endian de Host a Endian de Network

    if (bind(listeningSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Error: bind fallido" << '\n';
        return -1;
    }

    if (listen(listeningSocket, 5) < 0) {
        std::cerr << "Error: listen fallido" << '\n';
        return -1;
    }

    int commSocket;
    std::vector<thread*> connections;
    while(true) {
        std::cout << "Esperando peticiones..." << '\n';
        socklen_t addrlen = sizeof(address);

        commSocket = accept(listeningSocket, (struct sockaddr *)&address, &addrlen);
        if (commSocket < 0) {
            std::cerr << "Error: accept fallido" << '\n';
            return -1;
        }
        std::cout << "Conexión estrablecida con " << inet_ntoa(address.sin_addr) << '\n';

        connections.push_back(new thread(connection, commSocket));
    }


    close(listeningSocket);
    close(commSocket);
}
