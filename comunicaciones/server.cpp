#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h> // read

int main() {
    const int port = 8080;
    int listeningSocket, commSocket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *message = "Hola, estoy aquí para servirte";

    if ((listeningSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    if (setsockopt(listeningSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cerr << "Error: puerto en uso" << '\n';
        return -1;
    }
    /*

    */
    address.sin_family = AF_INET; // Address Family IPv4
    address.sin_addr.s_addr = INADDR_ANY; // IP de esta máquina
    address.sin_port = htons(port); // Puerto de Endian de Host a Endian de Network

    /*
        bind: Asignación de dirección IP y puerto
            sockfd: socket file descriptor
            serv_addr: Familia, IP y puerto del servidor
            addrlen: Tamaño de la estructura que almacena la dirección
        Devuelve -1 en caso de error
    */
    if (bind(listeningSocket, (struct sockaddr *)&address, sizeof(address))<0) {
        std::cerr << "Error: bind fallido" << '\n';
        return -1;
    }

    /*
        listen: Se prepara para esperar una conexión en el socket indicado
        sockfd: Socket file descriptor
        backlog: Número de conexiones (clientes) en espera al mismo tiempo
    */
    if (listen(listeningSocket, 5) < 0) {
        std::cerr << "Error: listen fallido" << '\n';
        return -1;
    }

    /*
        accept: Espera una conexión
        sockfd: Socket file descriptor
        serv_addr: Dirección de donde se espera
        addrlen: Tamaño de serv_addr
    */
    if ((commSocket = accept(listeningSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        std::cerr << "Error: accept fallido" << '\n';
        return -1;
    }

    valread = read( commSocket , buffer, 1024);
    std::cout << "Mensaje recibido: " << buffer << '\n';
    send(commSocket , message , strlen(message) , 0 );
    std::cout << "Mensaje enviado: " << message << '\n';
}
