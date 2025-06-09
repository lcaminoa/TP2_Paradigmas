#include "../Headers/Pokemon.hpp"

Pokemon::Pokemon(std::string newName, int newXp) : nombre(newName), xp(newXp) {}

std::string Pokemon::getNombre() const {
    return nombre;
}

int Pokemon::getXP() const {
    return xp;
}

bool Pokemon::operator==(const Pokemon& other) const {
    return nombre == other.nombre && xp == other.xp;
}