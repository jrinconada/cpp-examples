#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h> // strlen
#include <unistd.h> // read
#include <arpa/inet.h> // inet_aton

int main() {
    const int port = 8080;
    const int bufferSize = 1024;
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serverAddress;
    const char *message = "Hola, hago peticiones";
    char buffer[bufferSize] = {0};

    /*
        socket: Creación de un socket
            domain (AF_INET): Address Family IPv4
            type (SOCK_STREAM): Socket TCP
            protocol (0): TODO what is that???
        Devuelve un número que representa el descriptor de fichero, -1 en caso de error
    */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    memset(&serverAddress, '0', sizeof(serverAddress));

    // TODO This and the next part is a little obscure
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    /*
        inet_aton: Transforma dirección IP de texto a binario
            domain (AF_INET): Address Family IPv4
            text ("127.0.0.1"): IP de la máquina actual (localhost)
            serv_addr (serverAddress): IP y puerto del servidor
        Devuelve un número mayor que cero si todo va bien
    */
    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr)<=0) {
        std::cerr << "Error: IP inválida" << '\n';
        return -1;
    }

    /*
        connect: Intenta conectar con un servidor
            sockfd: Socket file descriptor
            serv_addr: IP y puerto del servidor
            addrlen: Tamaño de la estructura serv_addr
        Devuelve -1 si hay un error
    */
    if (connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Error: fallo de conexión" << '\n';
        return -1;
    }

    /*
        send: Envía un mensaje
            sockfd: Socket file descriptor
            message: Una cadena de texto
            message_len: Tamaño del mensaje
    */
    send(sock , message , strlen(message) , 0);
    std::cout << "Mensaje enviado" << message << '\n';

    /*
        read: Leer bytes del Socket
        sockfd: Socket file descriptor
        buffer: Almacenamiento de los bytes leídos
        buffer_len: Tamaño del buffer
    */
    valread = read(sock , buffer, bufferSize);
    std::cout << "Mensaje recibido: " << buffer << '\n';
}
