#include <iostream> // cout
#include <sys/socket.h> // sockaddr, socklen_t
#include <stdlib.h> // atoi
#include <netinet/in.h> // sockaddr_in
#include <string.h> // strlen
#include <unistd.h> // read, close
#include <arpa/inet.h> // inet_aton

int main(int argc, char const *argv[]) {
    const int bufferSize = 1024;

    // Usar localhost o recibir IP como primer parámetro del programa
    const char* ip = "127.0.0.1";
    if (argc > 1) {
        ip = argv[1];
    }

    // Usar puerto 8888 o recibirlo como segundo parámetro del programa
    int port = 8888;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    // SOCK_DGRAM y IPPROTO_UDP indican que se va a usar UDP
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    // Dirección del servidor
    struct sockaddr_in serverAddress;
    memset(&serverAddress, '0', sizeof(serverAddress)); // Limpia estructura serverAddress
    serverAddress.sin_family = AF_INET; // Address Family IPv4
    serverAddress.sin_port = htons(port); // Puerto de Endian de Host a Endian de Network

    if(inet_aton(ip, &serverAddress.sin_addr) <= 0) {
        std::cerr << "Error: IP inválida" << '\n';
        return -1;
    }

    const char *message = "Hola, hago peticiones";
    /*
        sendto: Envía un mensaje a un receptor
            sockfd: Socket file descriptor
            buffer: Mensaje (pueder ser un puntero a cualquier dato)
            n: Número de bytes a enviar
            flags: Opciones (0 es sin opciones)
            addr: Dirección de envío
            addr_len: Tamaño de addr
    */
    sendto(sock, message, strlen(message), 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    std::cout << "Mensaje enviado: " << message << '\n';

    std::cout << "Esperando mensaje..." << '\n';
    struct sockaddr_in address;
    char buffer[bufferSize] = {0};
    socklen_t addrlen = sizeof(address);
    /*
        recvfrom: Leer bytes del Socket
            sockfd: Socket file descriptor
            buffer: Almacenamiento de los bytes leídos
            buffer_len: Tamaño del buffer
            flags: Opciones (0 es sin opciones)
            addr: Dirección de recepción (entrada)
            addr_len: Tamaño de addr
        Devuelve el número de bytes leídos o -1 si hay un error
    */
    int n = recvfrom(sock, buffer, bufferSize, 0, (struct sockaddr *)&address, &addrlen);
    if (n > 0) {
        std::cout << "Mensaje recibido: " << buffer << '\n';
    } else {
        std::cerr << "Error: recepción del mensaje" << '\n';
    }
    std::cout << "Recibida petición de " << inet_ntoa(address.sin_addr) << '\n';

    /*
        close: Cerrar socket
            sockfd: Socket file descriptor
    */
    close(sock);
}
