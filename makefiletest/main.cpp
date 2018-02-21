// Con <> el fichero debe estar en un directorio include
#include <iostream> // Las librerías de C++ no suelen llevar .h
// Con "" el fichero puede estar en el directorio indicado o en el include
#include "calculator.h"
using namespace std;

int main(int argc, char const *argv[]) {

    Calculator calculator;
    cout << "Resultado: " << calculator.sum(1,3) << endl;

    return 0;
}
