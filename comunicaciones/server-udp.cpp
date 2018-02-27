#include <iostream> // cout
#include <sys/socket.h> // sockaddr, socklen_t
#include <stdlib.h> // atoi
#include <netinet/in.h> // sockaddr_in
#include <string.h> // strlen
#include <unistd.h> // read, close

int main(int argc, char const *argv[]) {
    const int bufferSize = 1024;

    // Usar puerto 8888 o recibirlo como segundo parámetro del programa
    int port = 8888;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    // SOCK_DATAGRAM y IPPROTO_UDP indican que se va a usar UDP
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_UDP);
    if (sock < 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    // Reutilizar IP y puerto
    int enable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable))) {
        std::cerr << "Error: puerto en uso" << '\n';
        return -1;
    }

    // Asignar IP y puerto
    struct sockaddr_in address;
    address.sin_family = AF_INET; // Address Family IPv4
    address.sin_addr.s_addr = INADDR_ANY; // IP de esta máquina
    address.sin_port = htons(port); // Puerto de Endian de Host a Endian de Network

    // Asociar IP y puerto al socket
    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Error: bind fallido" << '\n';
        return -1;
    }

    std::cout << "Esperando mensaje..." << '\n';
    char buffer[bufferSize] = {0};
    /*
        recvfrom: Leer bytes del Socket
            sockfd: Socket file descriptor
            buffer: Almacenamiento de los bytes leídos
            buffer_len: Tamaño del buffer
        Devuelve el número de bytes leídos o -1 si hay un error
    */
    int n = recvfrom(sock, buffer, bufferSize, 0, );
    if (n > 0) {
        std::cout << "Mensaje recibido: " << buffer << '\n';
    } else {
        std::cerr << "Error: recepción del mensaje" << '\n';
    }

    const char *message = "Hola, estoy aquí para servirte";
    /*
        sendto: Envía un mensaje
            sockfd: Socket file descriptor
            buffer: Mensaje (pueder ser un puntero a cualquier dato)
            n: Número de bytes a enviar
            flags: Opciones (0 es sin opciones)
        Devuelve el número de bytes enviados o -1 si hay un error
    */
    sendto(sock, message, strlen(message), 0);
    std::cout << "Mensaje enviado: " << message << '\n';

    /*
        close: Cerrar socket
            sockfd: Socket file descriptor
    */
    close(sock);
    close(sock);
}
