#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include "Pokemon.hpp"
#include "PokemonInfo.hpp"
#include <map>

class Pokedex {
private:
    std::unordered_map<Pokemon, PokemonInfo> info;

};

#endif //POKEDEX_HPP