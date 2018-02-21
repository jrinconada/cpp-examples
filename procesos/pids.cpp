#include <iostream>
#include <unistd.h>

int main () {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        std::cout << "Soy el hijo: " << getpid();
        std::cout << " Mi padre es: " << getppid() << '\n';
    } else {
        std::cout << "Soy el padre: " << getpid();
        std::cout << " Mi hijo es: " << pid << '\n';
    }
}
