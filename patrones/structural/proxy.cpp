#include <iostream>
#include <unistd.h>
using namespace std;

// Servirá para hacer peticiones web
class WebRequest {
public:
    virtual string ping() = 0; // Ping devolverá una
};

// Proxy: Actúa como una petición web para pruebas
class FakeRequest : public WebRequest {
public:
    string ping() {
        usleep(300000);
        std::cout << " . " << '\n';
        usleep(400000);
        std::cout << " . "  << '\n';
        usleep(500000);
        std::cout << " . " << '\n';
        usleep(600000);
        return "pong";
    }
};

class RealRequest : public WebRequest {
public:
    string ping() {
        // Aquí se implenentará la petición real
        return "No está implementado aún";
    }
};

int main () {
    FakeRequest request;
    std::cout << "ping?" << '\n';
    std::cout << request.ping() << '\n';
}
