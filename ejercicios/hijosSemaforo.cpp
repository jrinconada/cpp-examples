#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h> // strlen
#include <iomanip>
#include <semaphore.h> // sem_open, sem_unlink, sem_post, sem_wait
#include <fcntl.h> // O_CREAT, O_EXCL

// Compilacion con -pthread
int main(int argc, char const *argv[]) {
    pid_t pid;
    int status;
    sem_t *sem = sem_open("semaphore", O_CREAT|O_EXCL, 0, 1);
    sem_unlink("semaphore");

    for (int i = 1; i < argc; i++) {
        pid = fork();
        if (pid == 0) { // Hijos
            for (int j = atoi(argv[i]); j > 0; j--) {
                sem_wait(sem);
                std::cout << std::setw(i * 4) << j << '\n';
                sem_post(sem);
                sleep(1);
            }
            exit(atoi(argv[i]));
        }
    }

    for (int i = 1; i < argc; i++) {
        wait(&status);
    }
}
