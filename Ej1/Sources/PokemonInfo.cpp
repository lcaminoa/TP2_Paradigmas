#include "../Headers/PokemonInfo.hpp"

PokemonInfo::PokemonInfo(std::string newTipo, std::string newDescripcion, std::map<std::string, int> newAtaques, std::array<int, 3> newXPProxNivel) :
        tipo(newTipo), descripcion(newDescripcion), ataquesDisponiblesPorNivel(newAtaques), xpProximoNivel(newXPProxNivel) {}

PokemonInfo::PokemonInfo() = default;

std::string PokemonInfo::getTipo() const {
    return tipo;
}

std::string PokemonInfo::getDescripcion() const {
    return descripcion;
}

std::map<std::string, int> PokemonInfo::getAtaquesDisponiblesPorNivel() const {
    return ataquesDisponiblesPorNivel;
}

std::array<int, 3> PokemonInfo::getXpProximoNivel() const {
    return xpProximoNivel;
}