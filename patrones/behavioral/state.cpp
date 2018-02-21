#include <iostream>

struct Light;

struct State {
    virtual void on(Light* l) {
        // Transición a encendida cuando ya está encendida
        std::cout << "La luz ya está encendida" << '\n';
    }

    virtual void off(Light* l) {
        // Transición a apagada cuando ya está apagada
        std::cout << "La luz ya está apagada" << '\n';
    }
};

struct On : State {
    On() {
        // Estado de luz encendida
        std::cout << "Luz encendida!" << '\n';
    }
    void off(Light* l);
};

struct Off : State {
    Off() {
        // Estado de luz apagada
        std::cout << "Luz apagada!" << '\n';
    }
    void on(Light* l);
};

struct Light {
    State* state;
    Light() {
        state = new Off();
    }
    void setState(State* s) {
        state = s;
    }
    void on() {
        state->on(this);
    }
    void off() {
        state->off(this);
    }
};

// Representa una transición de encendida a apagada
void On::off(Light* l) {
    std::cout << "Apagando luz" << '\n';
    l->setState(new Off()); // Se crea un nuevo estado de apagado
    delete this; // Se borra el estado actual de encendido
}

// Representa una transición de apagada a encendida
void Off::on(Light* l) {
    std::cout << "Encendiendo luz" << '\n';
    l->setState(new On()); // Se crea un nuevo estado de apagado
    delete this; // Se borra el estado actual de encendido
}

int main() {
    Light light;
    std::cout << "------" << '\n';
    light.on();
    std::cout << "------" << '\n';
    light.off();
    std::cout << "------" << '\n';
    light.off();
    std::cout << "------" << '\n';
}
