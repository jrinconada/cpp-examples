#include <vector>
#include "recipe.cpp"

class Chef {
    void cut(int cuttingTime) {
        lock_guard<mutex> guard(knife);
        for (size_t i = 0; i < cuttingTime; i++) {
            std::cout << "c" + name + " : " + (i + 1) + " seg" + '\n';
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }
    void bake(int bakingTime) {
        lock_guard<mutex> guard(oven);
        for (size_t i = 0; i < bakingTime; i++) {
            std::cout << "    h" + name + " : " + (i + 1) + " seg" + '\n';
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }
public:
    vector<Recipe> recipes;
    int name;
    string type;

    Chef(int n, string t = "") : name(n), type(t) {}

    void cook() {
        for (auto& r : recipes) {
            if (type == "cutter") {
                cut(r.cuttingTime);
            } else if (type == "baker") {
                bake(r.bakingTime);
            } else {
                cut(r.cuttingTime);
                bake(r.bakingTime);
            }
        }
    }
};
