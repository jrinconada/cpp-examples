
class Recipe {
public:
    string name;
    int cuttingTime;
    int bakingTime;
    Recipe() {}
    Recipe(string n, int c, int b) : name(n), cuttingTime(c), bakingTime(b) {}
};
