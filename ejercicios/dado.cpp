#include <iostream>

int getSides(); // Pedir caras de un dado

int throwDice(int sides);

int main() {
    int dices;
    std::cin >> dices;

    int result = 0;
    for (size_t i = 0; i < dices; i++) {
        int theThrow = throwDice(getSides());
        result = result + theThrow;
        std::cout << theThrow << '\n';
    }

    std::cout << result << '\n';
}
