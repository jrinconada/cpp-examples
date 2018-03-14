#include <iostream>
#include <thread>
#include <chrono>


struct Train {
    std::string name;
    Train(std::string n) : name(n) {}

    void go() {
        std::cout << name << " empiezo" << '\n';
        for (size_t i = 0; i < 4; i++) {
            if (name == "B") {
                std::cout << "    .\n";
            } else { // A
                std::cout << ".\n";
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "Fin de trayecto." << '\n';
    }
};

void start(Train t) {
    t.go();
}

int main() {
    Train t1("A");
    std::thread threadTrain1(start, t1);
    Train t2("B");
    std::thread threadTrain2(start, t2);
    threadTrain1.join();
    threadTrain2.join();
}
