#include <iostream>
#include <vector>

class Line {
public:
    void draw () {
        std::cout << "_____________" << '\n';
    }
};

// Un grupo de líneas es también una línea
class LineGroup : public Line {
public:
    std::vector<Line> lines;

    void draw () { // Mismo método que la línea pero distinto comportamiento
        for (size_t i = 0; i < lines.size(); i++) {
            lines[i].draw();
        }
        std::cout << "." << '\n';
    }
};

int main () {
    LineGroup group;
    Line line1;
    line1.draw();
    Line line2;

    group.lines.push_back(line1);
    group.lines.push_back(line2);
    group.draw();

    LineGroup subGroup;
    Line line3;
    subGroup.lines.push_back(line3);
    subGroup.draw();

    // Se puede añadir un grupo a un grupo
    group.lines.push_back(subGroup);
    group.draw();
}
