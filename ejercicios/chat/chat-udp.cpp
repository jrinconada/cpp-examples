#include "NetworkManager.cpp"

int main () {
    // Inicialización
    NetworkManager nm;
    if (!nm.init()) {
        std::cout << "Error de conexión" << '\n';
        return -1;
    }

    // Recepción
    Message* message = nm.revieve();
    std::cout << inet_ntoa(message->user.address.sin_addr)
    << " dice " << message->text << '\n';

    // envío
    nm.send(message);

    // Finalización
    nm.end();
}
