#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h> // strlen

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

            for (int j = atoi(argv[i]); j > 0; j--) {
                // write(p[i-1][1], argv[i], strlen(argv[i]) + 1);
                write(p[i-1][1], &j, 1);
                sleep(1);
            }

            close(p[i-1][1]);
            exit(atoi(argv[i]));
        }
    }

    // Padre
    char count = '9';
    while (readBytes != 0) {
        for (size_t i = 0; i < argc-1; i++) {
            if ((int) count == 1){
                readBytes = 0;
                continue;
            }

            close(p[i][1]);
            readBytes = read(p[i][0], &count, 1);

            if (readBytes != 0) {
                std::cout << "Mensaje: " << (int) count << '\n';
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
