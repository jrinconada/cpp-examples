#include <vector>
#include <string>
#include <mutex>
#include "../../hilos/semaphore.cpp"
#include "recipe.cpp"

mutex knife;
mutex oven;

Semaphore semaphore;

class Chef {
    void cut(Recipe* r) {
        lock_guard<mutex> guard(knife);
        for (int i = 0; i < r->cuttingTime; i++) {
            std::cout << name + " cortando " + r->name
            + ", " + to_string(i + 1) + " seg\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    void bake(Recipe* r) {
        lock_guard<mutex> guard(oven);
        for (int i = 0; i < r->bakingTime; i++) {
            std::cout << name + " horneando " + r->name
            + ", " + to_string(i + 1) + " seg\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        r->prom.set_value(r->name);
    }
public:
    vector<Recipe*> recipes;
    string name;
    string type;

    Chef(string n, string t = "") : name(n), type(t) {}

    void cook() {
        for (auto& r : recipes) {
            if (type == "cutter") {
                cut(r);
                semaphore.notify();
            } else if (type == "baker") {
                semaphore.wait();
                bake(r);
            } else {
                cut(r);
                bake(r);
            }
        }
    }
};
