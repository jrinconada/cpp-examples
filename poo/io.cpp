#include <iostream>
#include <iomanip> // Formato de la entrada / salida por consola
using namespace std;

int main() {
    double number = 374.39474;
    cout << number << '\n'; // 374.395
    cout << setprecision(10); // Se imprimen 10 números
    cout << number << '\n'; // 374.39474
    cout << 274749.595847735 << '\n'; // 274749.5958

    cout << setw(20) << number << '\n'; // Ancho total de 20 caracteres
    cout << number << '\n'; // Sólo se aplica una vez
    cout << setw(20) << "Hola que tal" << '\n'; // También funciona con texto
    cout << setw(20) << "Si el texto es más largo no tiene efecto" << '\n';

    // Precisión de decimales
    cout << fixed << setprecision(2); // Se imprimen 2 decimales
    // Cambiar carater de relleno
    cout << setw(20) << setfill('-') << number << setw(10) << 23.536 << '\n';

    // También se aplica al obtener la entrada por consola
    double userNumber;
    std::cin >> userNumber;
    std::cout << userNumber << '\n';
}
