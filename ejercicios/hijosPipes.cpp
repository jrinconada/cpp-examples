#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h> // strlen

int main(int argc, char const *argv[]) {
    pid_t pid;
    int status;
    int p[2];
    char buffer[100];
    int readBytes = -1;

    for (int i = 1; i < argc; i++) {
        pipe(p);
    }

    for (int i = 1; i < argc; i++) {
        pid = fork();
        if (pid == 0) { // Hijos
            close(p[0]);
            std::cout << "Hijo durmiendo " << argv[i] << '\n';

            for (int j = atoi(argv[i]); j > 0; j--) {
                write(p[1], &j, sizeof(int));
                sleep(1);
            }

            exit(atoi(argv[i]));
        }
    }

    // Padre
    while (readBytes != 0) {
        close(p[1]);
        readBytes = read(p[0], buffer, sizeof(int));
        if (readBytes != 0) {
            std::cout << "Mensaje: " << (int) buffer[0] << '\n';
        }
    }

    for (int i = 1; i < argc; i++) {
        wait(&status);
        std::cout << "Hijo terminado " << WEXITSTATUS(status) << '\n';
        close(p[0]);
    }
    std::cout << "Mis hijos han terminado" << '\n';

}
