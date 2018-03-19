#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h> // strlen

/*
    ./a.out 4 5
    4
        5
    3
        4
    2
        3
    1
        2
    1
*/

int main(int argc, char const *argv[]) {
    pid_t pid;
    int status;
    int p[argc][2];
    char buffer[100];
    int readBytes = -1;

    for (size_t i = 1; i < argc; i++) {
        pipe(p[i-1]);
    }

    for (size_t i = 1; i < argc; i++) {
        pid = fork();
        if (pid == 0) { // Hijos
            close(p[i-1][0]);
            std::cout << "Hijo durmiendo " << argv[i] << '\n';

            for (size_t j = 0; j < atoi(argv[i]); j++) {
                write(p[i-1][1], argv[i], strlen(argv[i]) + 1);
                sleep(1);
            }

            close(p[i-1][1]);
            exit(atoi(argv[i]));
        }
    }

    // Padre
    while (readBytes != 0) {
        for (size_t i = 0; i < argc-1; i++) {
            close(p[i][1]);
            readBytes = read(p[i][0], buffer, sizeof(buffer));
            if (readBytes != 0) {
                std::cout << "Mensaje: " << buffer << '\n';
            }
        }
    }

    for (size_t i = 1; i < argc; i++) {
        wait(&status);
        std::cout << "Hijo: " << WEXITSTATUS(status) << '\n';
        close(p[i-1][0]);
    }
    std::cout << "Mis hijos han terminado" << '\n';

}
