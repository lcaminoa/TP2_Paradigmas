#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include "Pokemon.hpp"
#include "PokemonInfo.hpp"
#include <unordered_map>
#include <iostream>

class Pokedex {
private:
    std::unordered_map<Pokemon, PokemonInfo, HashPokemon> info;
    std::string archivo;
public:
    Pokedex();
    Pokedex(const std::string& archivo); // Constructor con archivo

    void mostrar(const Pokemon& p) const;
    void mostrarTodos() const;
    void agregar(const Pokemon& p, const PokemonInfo& info);
};

#endif //POKEDEX_HPP