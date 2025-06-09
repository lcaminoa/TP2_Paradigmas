#include "../Headers/Pokedex.hpp"
#include <utility>
#include <fstream>

Pokedex::Pokedex() = default; // Crea pokedex vacía

Pokedex::Pokedex(const std::string& archivo) : archivo(archivo) {
    // Falta esto...
}

void Pokedex::mostrar(const Pokemon& p) const {
    auto it = info.find(p);

    if (it != info.end()) {
        const PokemonInfo& info = it->second;
        std::cout << "Nombre: " << p.getNombre() << "\n";
        std::cout << "Experiencia: " << p.getXP() << "\n";
        std::cout << "Tipo: " << info.getTipo() << "\n";
        std::cout << "Descripción: " << info.getDescripcion() << "\n";

        std::cout << "Ataques disponibles:\n";
        for (const auto& [ataque, nivel] : info.getAtaquesDisponiblesPorNivel()) {
            std::cout << "  - " << ataque << " (desde nivel " << nivel << ")\n";
        }

        std::cout << "Experiencia necesaria para subir de nivel:\n";
        for (int xp : info.getXpProximoNivel()) {
            std::cout << "  - " << xp << "\n";
        }

    }
    else {
        std::cout << "¡Pokemon desconocido!\n";
    }
}

void Pokedex::mostrarTodos() const {
    for (const auto& par : info) {
        const Pokemon& p = par.first;
        std::cout << "-------------------------\n";
        mostrar(p);
    }
}

void Pokedex::agregar(const Pokemon& p, const PokemonInfo& info) {
    this->info[p] = info;
}
