#include <iostream>
#include <thread>
#include <sstream>
using namespace std;

void countDown(string name) {
    ostringstream text;
    for (int i = 30; i > 0; i--) {
        text << name << " : " << i << '\n';
        std::cout << text.str();
    }
}

int main() {
    thread t1(countDown, "HILO 1");
    // thread t2(countDown, "HILO 2");

    t1.join();
    // t2.join();
}
