#include "../Headers/Hangar.hpp"

std::mutex& Hangar::getZona(int i) {
    return zonas[i % 5];
}