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

void PokemonInfo::serializar(std::ofstream& out) const {
    size_t sizeTipo = tipo.size();
    out.write(reinterpret_cast<const char*>(&sizeTipo), sizeof(sizeTipo));
    out.write(tipo.c_str(), sizeTipo);

    size_t sizeDescripcion = descripcion.size();
    out.write(reinterpret_cast<const char*>(&sizeDescripcion), sizeof(sizeDescripcion));
    out.write(descripcion.c_str(), sizeDescripcion);

    size_t sizeAtaques = ataquesDisponiblesPorNivel.size();
    out.write(reinterpret_cast<const char*>(&sizeAtaques), sizeof(sizeAtaques));
    for (const auto& [nombre, nivel] : ataquesDisponiblesPorNivel) {
        size_t len = nombre.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(nombre.c_str(), len);
        out.write(reinterpret_cast<const char*>(&nivel), sizeof(nivel));
    }

    out.write(reinterpret_cast<const char*>(xpProximoNivel.data()), sizeof(int) * 3);
}

void PokemonInfo::deserializar(std::ifstream& in) {
    size_t sizeTipo;
    in.read(reinterpret_cast<char*>(&sizeTipo), sizeof(sizeTipo));
    tipo.resize(sizeTipo);
    in.read(&tipo[0], sizeTipo);

    size_t sizeDescripcion;
    in.read(reinterpret_cast<char*>(&sizeDescripcion), sizeof(sizeDescripcion));
    descripcion.resize(sizeDescripcion);
    in.read(&descripcion[0], sizeDescripcion);

    size_t sizeAtaques;
    in.read(reinterpret_cast<char*>(&sizeAtaques), sizeof(sizeAtaques));
    ataquesDisponiblesPorNivel.clear();
    for (size_t i = 0; i < sizeAtaques; ++i) {
        size_t len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        std::string ataque(len, ' ');
        in.read(&ataque[0], len);
        int nivel;
        in.read(reinterpret_cast<char*>(&nivel), sizeof(nivel));
        ataquesDisponiblesPorNivel[ataque] = nivel;
    }

    in.read(reinterpret_cast<char*>(xpProximoNivel.data()), sizeof(int) * 3);
}