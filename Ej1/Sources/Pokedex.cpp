#include "../Headers/Pokedex.hpp"
#include <utility>
#include <fstream>

Pokedex::Pokedex() = default; //Crea pokedex vacía

Pokedex::Pokedex(const std::string& archivo) : archivo(archivo) {
    cargarDesdeArchivo();
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
    guardarEnArchivo();
}



void Pokedex::guardarEnArchivo() {
    std::ofstream out(archivo, std::ios::binary);
    if (!out.is_open()) return;
    size_t size = info.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& [p, pi] : info) {
        p.serializar(out);
        pi.serializar(out);
    }
}

void Pokedex::cargarDesdeArchivo() {
    std::ifstream in(archivo, std::ios::binary);
    if (!in.is_open()) return;
    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
        Pokemon p;
        PokemonInfo pi;
        p.deserializar(in);
        pi.deserializar(in);
        info[p] = pi;
    }
}

