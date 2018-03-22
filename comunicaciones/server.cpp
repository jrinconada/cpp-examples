#include <iostream> // cout
#include <sys/socket.h> // sockaddr, socklen_t
#include <stdlib.h> // atoi
#include <netinet/in.h> // sockaddr_in
#include <string.h> // strlen
#include <unistd.h> // read, close
#include <arpa/inet.h> // inet_ntoa

int main(int argc, char const *argv[]) {
    const int bufferSize = 1024;

    // Usar puerto 8888 o recibirlo como segundo parámetro del programa
    int port = 8888;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    /*
        socket: Creación del socket de escucha
            domain: Address Family IPv4 (AF_INET)
            type: Socket TCP  (SOCK_STREAM)
            protocol: Con IPPROTO_TCP especificamos TCP
        Devuelve un número que representa el descriptor de fichero, -1 en caso de error
    */
    int listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listeningSocket < 0) {
        std::cerr << "Error: creación de socket" << '\n';
        return -1;
    }

    int enable = 1;
    /*
        setsockopt: Modificar opciones de red
            sockfd: Socket file descriptor
            level: Nivel de protocolo, para especificar nivel socket es SOL_SOCKET
            option_name: El nombre de la opción a modificar (SO_REUSEADDR y SO_REUSEPORT)
            option_val: Valor de la opción 0 desabilitado, 1 habilitado
            option_len: Tamaño de option_val
    */
    if (setsockopt(listeningSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable))) {
        std::cerr << "Error: puerto en uso" << '\n';
        return -1;
    }

    /*
        sockaddr_in: Estructura que representa una Familia, IP y puerto
    */
    struct sockaddr_in address;
    address.sin_family = AF_INET; // Address Family IPv4
    address.sin_addr.s_addr = INADDR_ANY; // IP 0.0.0.0 (todas las interfaces de red)
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

    std::cout << "Esperando peticiones..." << '\n';
    socklen_t addrlen = sizeof(address);
    /*
        accept: Espera una conexión
        sockfd: Socket file descriptor
        cli_addr: Dirección del cliente
        addrlen: Tamaño de serv_addr
    */
    int commSocket = accept(listeningSocket, (struct sockaddr *)&address, &addrlen);
    if (commSocket < 0) {
        std::cerr << "Error: accept fallido" << '\n';
        return -1;
    }
    std::cout << "Conexión estrablecida con " << inet_ntoa(address.sin_addr) << '\n';

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
