#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <fstream>

class Pokemon {
private:
    std::string nombre;
    int xp;
public:
    Pokemon(std::string newName, int newXp);
    Pokemon(); //Para usar al deserealizar

    std::string getNombre() const;
    int getXP() const;

    bool operator==(const Pokemon& other) const;
    void serializar(std::ofstream& out) const;
    void deserializar(std::ifstream& in);
};

struct HashPokemon {
    std::size_t operator()(const Pokemon& p) const {
        std::size_t h1 = std::hash<std::string>()(p.getNombre());
        std::size_t h2 = std::hash<int>()(p.getXP());
        return h1 ^ (h2 << 1); // Forma común para combinar hashes
    }
};

#endif //POKEMON_HPP