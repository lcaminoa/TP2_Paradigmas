#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

class Pokemon {
private:
    std::string nombre;
    int xp;
public:
    Pokemon(std::string newName, int newXp);

    std::string getNombre() const;
    int getXP() const;

    bool operator==(const Pokemon& other) const;
};

struct HashPokemon {
    std::size_t operator()(const Pokemon& p) const {
        return std::hash<std::string>()(p.getNombre());
    }
};

#endif //POKEMON_HPP