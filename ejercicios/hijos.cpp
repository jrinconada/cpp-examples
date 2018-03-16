#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    pid_t pid;
    int status;

    for (size_t i = 1; i < argc; i++) {
        pid = fork();
        if (pid == 0) {
            std::cout << "Hijo durmiendo " << argv[i] << '\n';
            sleep(atoi(argv[i]));
            exit(atoi(argv[i]));
        }
    }

    if (pid != 0) {
        for (size_t i = 1; i < argc; i++) {
            wait(&status);
            std::cout << "Hijo: " << WEXITSTATUS(status) << '\n';
        }
        std::cout << "Mis hijos han terminado" << '\n';
    }

}
