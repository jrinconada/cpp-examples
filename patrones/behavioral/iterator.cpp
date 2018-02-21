#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main () {
    // Inicialización en línea requiere C++11
    std::vector<string> goodbyes {"so long", "farewell", "auf wiedersehen", "adieu"};
    std::vector<string>::iterator it = goodbyes.begin();
    // Un iterator es un puntero al dato
    std::cout << "El primer elemento es: " << *it << '\n';

    it--;
    // Recorrer elementos usando sólo iteradores
    while (it++ != goodbyes.end()) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Recorrer vector con un for
    // Se pueden usar como una función: rbegin(goodbyes) es igual a goodbyes.rbegin()
    // Se suele usar auto para no escribirlo
    for (auto i = begin(goodbyes); i != end(goodbyes); i++) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';

    // For each usa iteradores internamente
    // Se suele usar & para ahorar memoria
    for (auto& bye : goodbyes) {
        std::cout << bye << ' ';
    }
    std::cout << '\n';
}
