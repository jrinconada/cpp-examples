#include <future>

class Recipe {
public:
    string name;
    int cuttingTime;
    int bakingTime;
    promise<string> prom;
    Recipe() {}
    Recipe(string n, int c, int b) : name(n), cuttingTime(c), bakingTime(b) {}
};
