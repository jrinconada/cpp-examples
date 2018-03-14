#include "arbol.h"

int main () {
    Suspect s;
    s.dniNumber = 1234;
    s.name = "Pepe";
    s.crime = "Ser malo";

    Tree suspects;
    suspects.init();
    suspects.insert(s.dniNumber, s);
}
