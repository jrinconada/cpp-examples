#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h> // strlen
#include <unistd.h> // read

int main(int argc, char const *argv[]) {
    const int bufferSize = 1024;

    // Usar puerto 8080 o recibirlo como segundo parámetro del programa
    int port = 8080;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    int listeningSocket;
    /*
        socket: Creación del socket de escucha
            domain: Address Family IPv4 (AF_INET)
            type: Socket TCP  (SOCK_STREAM)
            protocol: Protocolo IP es el 0
        Devuelve un número que representa el descriptor de fichero, -1 en caso de error
    */
    if ((listeningSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    int opt = 1;
    /*
        setsockopt: Permite resuar IP y puerto
            sockfd: socket file descriptor
            level:
            optname:
            optval: (1)
            optlen: Tamaño del valor de opt
    */
    if (setsockopt(listeningSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cerr << "Error: puerto en uso" << '\n';
        return -1;
    }

    /*
        sockaddr_in: Estructura que representa una Familia, IP y puerto
    */
    struct sockaddr_in address;
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
    if (bind(listeningSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
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

    int commSocket;
    socklen_t addrlen = sizeof(address);
    /*
        accept: Espera una conexión
        sockfd: Socket file descriptor
        serv_addr: Dirección de donde se espera
        addrlen: Tamaño de serv_addr
    */
    if ((commSocket = accept(listeningSocket, (struct sockaddr *)&address, &addrlen)) < 0) {
        std::cerr << "Error: accept fallido" << '\n';
        return -1;
    }

    char buffer[bufferSize] = {0};
    /*
        read: Leer bytes del Socket
            sockfd: Socket file descriptor
            buffer: Almacenamiento de los bytes leídos
            buffer_len: Tamaño del buffer
        Devuelve el número de bytes leídos o -1 si hay un error
    */
    int n = read(commSocket, buffer, bufferSize);
    if (n > 0) {
        std::cout << "Mensaje recibido: " << buffer << '\n';
    } else {
        std::cerr << "Error: recepción del mensaje" << '\n';
    }

    const char *message = "Hola, estoy aquí para servirte";
    /*
        send: Envía un mensaje
            sockfd: Socket file descriptor
            buffer: Mensaje (pueder ser un puntero a cualquier dato)
            n: Número de bytes a enviar
            flags: Opciones (0 es sin opciones)
        Devuelve el número de bytes enviados o -1 si hay un error
    */
    send(commSocket, message, strlen(message), 0);
    std::cout << "Mensaje enviado: " << message << '\n';

    /*
        close: Cerrar socket
            sockfd: Socket file descriptor
    */
    close(listeningSocket);
    close(commSocket);
}
