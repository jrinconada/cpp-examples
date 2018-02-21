#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) { // Código del hijo
        std::cout << "Soy el hijo haciendo cosas..." << '\n';
        sleep(2); // Detener la ejecución 2 segundos
        std::cout << "Soy el hijo y he acabado." << '\n';
    } else { // Código del padre
        std::cout << "Estoy esperando a mi hijo..." << '\n';
        wait(&status);
        std::cout << "Mi hijo ha acabado" << '\n';
    }
}
