#include <iostream> // cout, cerr
#include <unistd.h> // fork, pipe
#include <string.h> // strlen

int main() {
    int fd[2]; // El pipe
    int readBytes; // Bytes leídos
    pid_t pid; // Process id
    // char message[] = "Hola, soy tu hijo";
    char message[] = "Hola, soy tu hijo";
    char buffer[80];

    pipe(fd);

    if((pid = fork()) == -1) {
        std::cerr << "Error en el fork" << '\n';
        return -1;
    }

    if(pid == 0) {
        // El hijo cierra un lado del pipe
        close(fd[0]);
        // Envío del message por el pipe
        write(fd[1], message, strlen(message) + 1); // +1 (caracter de final de cadena)
    } else {
        // El padre cierra el otro lado del pipe
        close(fd[1]);
        // Leer del pipe
        readBytes = read(fd[0], buffer, sizeof(buffer));
        std::cout << buffer << '\n';
    }
}
