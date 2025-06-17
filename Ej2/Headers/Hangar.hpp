#pragma once

#include <mutex>
#include <array>

class Hangar {
private:
    std::mutex zonas[5]; //Al hacer esto, los mutex son inicializados automaticamente entonces no se necesita constructor
public:
    std::mutex* getZonas();
};
