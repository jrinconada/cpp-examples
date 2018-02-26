#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h> // read
#include <arpa/inet.h> // inet_pton
#define PORT 8080

int main() {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    const char *message = "Hola, hago peticiones";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        std::cerr << "Error: IP inválida" << '\n';
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Error: fallo de conexión" << '\n';
        return -1;
    }

    send(sock , message , strlen(message) , 0 );
    std::cout << "Mensaje enviado" << message << '\n';
    valread = read( sock , buffer, 1024);
    std::cout << "Mensaje recibido: " << buffer << '\n';
}
