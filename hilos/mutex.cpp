#include <iostream>
#include <thread>
#include <sstream>
using namespace std;

mutex mtx;

void print(string name, int i) {
    ostringstream text;
    text << name << " : " << i << '\n';
    cout << text.str();
}

void printMutex(string name, int i) {
    mtx.lock();
    cout << name << " : " << i << '\n';
    mtx.unlock(); // Podría quedarse sin cerrar (por ejemplo por excepción o Ctrl-C)
}

void printMutexGuard(string name, int i) {
    lock_guard<mutex> guard(mtx); // Previene la posibilidad de quedarse abierto
    cout << name << " : " << i << '\n';
}

void countDown(string name) {

    for (int i = 30; i > 0; i--) {
        // Acceso a cout con condiciones de carrera
        cout << name << " : " << i << '\n';
        
        // Acceso atómico a cout:
        print(name, i);

        // Acceso con mutex:
        printMutex(name, i);

        // Acceso con mutex guard:
        printMutexGuard(name, i);
    }
}

int main() {
    thread t1(countDown, "HILO 1");
    thread t2(countDown, "HILO 2");

    t1.join();
    t2.join();
}
