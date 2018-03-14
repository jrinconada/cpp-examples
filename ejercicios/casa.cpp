#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Light {

};

class Heater {

};

class Blind {

};

class Appliance { // Electrodoméstico
protected:
    string name;
public:
    string getName() {
        return name;
    }
};


class Fridge : public Appliance {
public:
    static const string fridgeName;
    Fridge() {
        name = fridgeName;
    }
};

class Oven : public Appliance {
public:
    static const string ovenName;
    Oven() {
        name = ovenName;
    }
};

class Washer : public Appliance {
public:
    static const string washerName;
    Washer() {
        name = washerName;
    }
};
const string Fridge::fridgeName = "Fridge";
const string Washer::washerName = "Washer";
const string Oven::ovenName = "Oven";

class Room {
    friend class House;
    vector<Light> lights;
    Blind blind;
public:
    void installLight() {
        lights.push_back(Light());
    }
    void install(Light light) {
        lights.push_back(light);
    }
    void install(Blind blind) {
        this->blind = blind;
    }
};

class RegularRoom : public Room {
    Heater heater;
public:
    RegularRoom() {
        installLight();
        install(Heater());
    }
    void install(Heater heater) {
        this->heater = heater;
    }
};

class Kitchen : public Room {
    /* Electrodomésticos
        0 - Nevera
        1 - Nevera (opcional)
        2 - Horno (opcional)
        3 - Lavadora (opcional)
    */
    array<Appliance, 4> appliances;
public:
    Kitchen() {
        appliances[0] = Fridge();
    }
    void install(Appliance appliance) {
        if (appliance.getName() == Fridge::fridgeName) {
            appliances[1] = appliance;
        } else if (appliance.getName() == Oven::ovenName) {
            appliances[2] = appliance;
        } else if (appliance.getName() == Washer::washerName) {
            appliances[3] = appliance;
        }
    }
};

class House {
    vector<Room> rooms;
    House() {
        rooms.push_back(Room());
    }
};

int main() {
    RegularRoom bedroom;
    bedroom.installLight(); // Añadir luz
}
