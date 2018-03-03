#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void son (int seconds) {
    std::cout << "Soy un hijo haciendo cosas..." << '\n';
    sleep(seconds); // Detener la ejecución 2 segundos
    std::cout << "Soy un hijo y he acabado." << '\n';
}

int main () {
    pid_t pid;

    pid = fork(); // Se crea un hijo
    if (pid == 0) { // Código del hijo
        son(2); // Un hijo duerme 2 segundos
    } else { // Código del padre
        pid = fork(); // Se crea otro hijo
        if (pid == 0) {
            son(3); // Otro hijo duerme 3 segundos
        } else {
            std::cout << "Estoy esperando a mis hijos..." << '\n';
            wait(NULL); // Espero a un hijo
            wait(NULL); // Espero a otro hijo
            std::cout << "Mis hijos ha acabado" << '\n';
        }

    }
}
