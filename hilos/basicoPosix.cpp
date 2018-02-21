#include <iostream>
#include <pthread.h>

void* task (void*) {
    std::cout << "Soy un hilo" << '\n';
    return NULL;
}

int main () {
    pthread_t t;

    pthread_create(&t, NULL, task, NULL);

    pthread_join(t, NULL);
}
