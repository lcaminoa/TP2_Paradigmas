#ifndef POKEMONINFO_HPP
#define POKEMONINFO_HPP

#include <string>
#include <map>
#include <fstream>

class PokemonInfo {
private:
    std::string tipo;
    std::string descripcion;
    std::map<std::string, int> ataquesDisponiblesPorNivel;
    std::array<int, 3> xpProximoNivel;
public:
    PokemonInfo(std::string newTipo, std::string newDescripcion, std::map<std::string, int> newAtaques, std::array<int, 3> newXPProxNivel);
    PokemonInfo(); // Por si no hay datos al buscar un pokemon en agregar()

    std::string getTipo() const;
    std::string getDescripcion() const;
    std::map<std::string, int> getAtaquesDisponiblesPorNivel() const;
    std::array<int, 3> getXpProximoNivel() const;
    void serializar(std::ofstream& out) const;
    void deserializar(std::ifstream& in);
};

#endif //POKEMONINFO_HPP