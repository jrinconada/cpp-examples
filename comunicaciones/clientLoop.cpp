#include <iostream> // cout
#include <sys/socket.h> // sockaddr, socklen_t
#include <stdlib.h> // atoi
#include <netinet/in.h> // sockaddr_in
#include <string.h> // strlen
#include <unistd.h> // read, close
#include <arpa/inet.h> // inet_aton
#include <thread>

void connection(int commSocket) {
    const int bufferSize = 1024;

    while(true) {
        char buffer[bufferSize] = {0};

        while(recv(commSocket, buffer, sizeof(buffer), 0) <= 0);
        std::cout << "Mensaje recibido: " << buffer << '\n';
    }
}

int main(int argc, char const *argv[]) {
    const char* ip = "127.0.0.1";
    if (argc > 1) {
        ip = argv[1];
    }
    int port = 8888;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        std::cerr << "Error: creación de socket fallida" << '\n';
        return -1;
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, '0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if(inet_aton(ip, &serverAddress.sin_addr) <= 0) {
        std::cerr << "Error: IP inválida" << '\n';
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Error: fallo de conexión" << '\n';
        return -1;
    }

    std::thread t(connection, sock);

    while (true) {
      std::string message;
      std::cout << "Mensaje: ";
      getline(std::cin, message);

      send(sock, message.c_str(), strlen(message.c_str()), 0);
      std::cout << "Mensaje enviado: " << message << '\n';
    }

    t.join();
    close(sock);
}
