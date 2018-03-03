#include <iostream>
#include <unistd.h>
#include <stdlib.h>
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
        exit(42); // Termina y envía un código de retorno
    } else { // Código del padre
        std::cout << "Estoy esperando a mi hijo..." << '\n';
        pid_t child = wait(&status); // Wait es necesario para no crear procesos "zombie"
        // WEXITSTATUS descarta la información extra de status dejando sólo el valor de retorno
        std::cout << "Mi hijo " << child << " ha acabado con el código: " << WEXITSTATUS(status) << '\n';
    }
}
