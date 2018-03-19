#include <iostream> // cout
#include <semaphore.h> // sem_open, sem_unlink, sem_post, sem_wait
#include <unistd.h> // fork, getpid, sleep
#include <sys/types.h> // wait
#include <sys/wait.h> // wait
#include <fcntl.h> // O_CREAT, O_EXCL

// Compilación con -pthread
int main() {
    // O_CREAT|O_EXCL : Error si el semáforo ya existe
    // mode: Permisos
    // value: Valor incial del semáforo (número de bolas)
    sem_t *sem = sem_open("semaphore", O_CREAT|O_EXCL, 0, 1);
    sem_unlink("semaphore"); // El semáforo se borrará al terminar de usarse
    int child = fork();
    std::cout << getpid() << " esperando..." << '\n';
    sem_wait(sem);
    std::cout << getpid() << " fin de espera" << '\n';
    sleep(1);
    std::cout << getpid() << " durmiendo..." << '\n';
    sem_post(sem);

    if(child > 0) {
        int status;
        std::cout << "Esperando al hijo..." << '\n';
        wait(&status);
    }

    std::cout << getpid() << " fin." << '\n';
    return 0;
}
