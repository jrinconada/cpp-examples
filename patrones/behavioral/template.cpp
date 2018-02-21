#include <iostream>

struct Game {
    int players;
    virtual void start() = 0;
    virtual bool end() = 0;
    virtual void turn() = 0;
    virtual void finish() = 0;

    Game(int players) : players(players) {}

    void play() {
        start();
        while (!end()) {
            turn();
        }
        finish();
    }
};

struct Chess : Game {
    bool checkMate;
    int turnNumber;
    Chess() : Game(2) {}
    void start() {
        std::cout << "Colocando las piezas..." << '\n';
        checkMate = false;
        turnNumber = 0;
    }
    bool end() {
        std::cout << "Comprobando jaque mate..." << '\n';
        return checkMate;
    }
    void turn() {
        if (turnNumber % 2 == 0) {
            std::cout << "Mueve jugador 1" << '\n';
        } else {
            std::cout << "Mueve jugador 2" << '\n';
        }
        turnNumber++;

        if (turnNumber == 10) {
            checkMate = true;
        }
    }
    void finish() {
        std::cout << "Jugador 1 ha ganado!" << '\n';
    }
};

int main() {
    Chess chessGame;
    std::cout << "Partida 1" << '\n';
    chessGame.play();
    std::cout << "---------" << '\n';
    std::cout << "Partida 2" << '\n';
    chessGame.play();
}
