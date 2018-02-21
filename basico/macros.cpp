#include <iostream> // include copia el fichero iostream en el fichero actual
/*
    MACROS
    Lo que empieza por #
    El preprocesador lo sustituye sin evaluarlo ni compilarlo.
*/
#define PI 3.1416 // Se sustituye en el código siempre que ponga PI
#define HELLO std::cout << "Hola!" << std::endl

#define DEBUG // Borrar esta línea en producción
#ifdef DEBUG // En modo DEBUG se muestran los logs
    #define LOG(M) std::cout << M << std::endl
#else // En producción no se genera el código de logs
    #define LOG(M)
#endif

#define FOR(I,F) for(I = 0; I < F; I++) // bucle for más corto
#define MAX(A,B) (A > B) ? A : B // Devuelve el número mayor de dos números

int main() {
    HELLO;
    float number = PI;
    LOG(number);

    int i = 1;
    FOR(i, 10) {
        std::cout << i << '\n';
    }

    int max = MAX(7,3);
    std::cout << max << '\n';
}
