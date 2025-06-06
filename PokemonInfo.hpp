#ifndef POKEMONINFO_HPP
#define POKEMONINFO_HPP

#include <string>
#include <map>

class PokemonInfo {
private:
    std::string tipo;
    std::string descripcion;
    std::map<std::string, int> ataquesDisponiblesPorNivel;
    std::array<int, 3> xpProximoNivel;
public:
    PokemonInfo(std::string newTipo, std::string newDescripcion, std::map<std::string, int> newAtaques, std::array<int, 3> newXPProxNivel);

    std::string getTipo() const;
    std::string getDescripcion() const;
    std::map<std::string, int> getAtaquesDisponiblesPorNivel() const;
    std::array<int, 3> getXpProximoNivel() const;
};

#endif //POKEMONINFO_HPP