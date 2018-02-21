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
    int status;

    pid = fork(); // Se crea un hijo
    if (pid == 0) { // Código del hijo
        son(5); // Un hijo duerme 5 segundos
    } else { // Código del padre
        pid = fork(); // Se crea otro hijo
        if (pid == 0) {
            son(2); // Otro hijo duerme 2 segundos
        } else {
            std::cout << "Estoy esperando a mi hijo..." << '\n';
            waitpid(pid, &status, 0); // Espero sólo al último hijo
            std::cout << "Mi último hijo ha acabado" << '\n';
        }

    }
}
