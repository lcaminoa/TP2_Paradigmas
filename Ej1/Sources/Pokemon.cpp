#include "../Headers/Pokemon.hpp"

Pokemon::Pokemon(std::string newName, int newXp) : nombre(newName), xp(newXp) {}
Pokemon::Pokemon() : nombre(""), xp(0) {}

std::string Pokemon::getNombre() const {
    return nombre;
}

int Pokemon::getXP() const {
    return xp;
}

bool Pokemon::operator==(const Pokemon& other) const {
    return nombre == other.nombre && xp == other.xp;
}

void Pokemon::serializar(std::ofstream& out) const {
    size_t sizeNombre = nombre.size();
    out.write(reinterpret_cast<const char*>(&sizeNombre), sizeof(sizeNombre));
    out.write(nombre.c_str(), sizeNombre);
    out.write(reinterpret_cast<const char*>(&xp), sizeof(xp));
}

void Pokemon::deserializar(std::ifstream& in) {
    size_t sizeNombre;
    in.read(reinterpret_cast<char*>(&sizeNombre), sizeof(sizeNombre));
    nombre.resize(sizeNombre);
    in.read(&nombre[0], sizeNombre);
    in.read(reinterpret_cast<char*>(&xp), sizeof(xp));
}