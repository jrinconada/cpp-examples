#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h> // strlen
#include <unistd.h> // read
#include <arpa/inet.h> // inet_aton

int main(int argc, char const *argv[]) {
    const int bufferSize = 1024;

    // Usar localhost o recibir IP como primer parámetro del programa
    const char* ip = "127.0.0.1";
    if (argc > 1) {
        ip = argv[1];
    }

    // Usar puerto 8080 o recibirlo como segundo parámetro del programa
    int port = 8080;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    int sock = 0;
    /*
        socket: Creación de un socket
            domain: Address Family IPv4 (AF_INET)
            type: Socket TCP  (SOCK_STREAM)
            protocol: Protocolo IP es el 0
        Devuelve un número que representa el descriptor de fichero, -1 en caso de error
    */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    // Dirección del servidor
    struct sockaddr_in serverAddress;
    memset(&serverAddress, '0', sizeof(serverAddress)); //
    serverAddress.sin_family = AF_INET; // Address Family IPv4
    serverAddress.sin_port = htons(port); // Puerto de Endian de Host a Endian de Network
    /*
        inet_aton: Transforma dirección IP de texto a binario
            domain: Address Family IPv4 (AF_INET)
            ip_text: IP como cadena de texto
            serv_addr: IP del servidor
        Devuelve un número mayor que cero si todo va bien
    */
    if(inet_aton(ip, &serverAddress.sin_addr) <= 0) {
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


    const char *message = "Hola, hago peticiones";
    /*
        send: Envía un mensaje
            sockfd: Socket file descriptor
            message: Una cadena de texto
            message_len: Tamaño del mensaje
            flags: Opciones (0 es sin opciones)
        Devuelve el número de bytes enviados o -1 si hay un error
    */
    send(sock, message, strlen(message), 0);
    std::cout << "Mensaje enviado" << message << '\n';

    /*
        read: Leer bytes del Socket
            sockfd: Socket file descriptor
            buffer: Almacenamiento de los bytes leídos
            buffer_len: Tamaño del buffer
        Devuelve el número de bytes leídos o -1 si hay un error
    */
    char buffer[bufferSize] = {0};
    int n = read(sock, buffer, bufferSize);
    if (n > 0) {
        std::cout << "Mensaje recibido: " << buffer << '\n';
    } else {
        std::cerr << "Error: recepción del mensaje" << '\n';
    }

    /*
        close: Cerrar socket
            sockfd: Socket file descriptor
    */
    close(sock);
}
