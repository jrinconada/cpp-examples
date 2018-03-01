
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Leer texto del pipe e imprimirlo por consola
void toConsole(int file) {
    FILE *stream;
    int c;
    stream = fdopen(file, "r");
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);
    }
    fclose(stream);
}

// Escribir en el pipe
void toPipe(int file) {
    FILE *stream;
    stream = fdopen(file, "w");
    fprintf(stream, "Hola hijo\n");
    fprintf(stream, "¿qué tal?\n");
    fclose(stream);
}

int main(void) {
    pid_t pid;
    int myPipe[2];

    // Creación de pipe
    if (pipe (myPipe)) {
        std::cerr << "Error al crear pipe" << '\n';
        return -1;
    }

    pid = fork ();
    if (pid == 0) {
        // Proceso hijo
        close(myPipe[1]);
        toConsole(myPipe[0]);
    } else if (pid < 0) {
        // Error al crear hijo
        std::cerr << "Error en el fork" << '\n';
        return -1;
    } else {
        // Proceso padre
        close(myPipe[0]);
        toPipe(myPipe[1]);
    }
}
