#ifndef HANGAR_HPP
#define HANGAR_HPP

#include <mutex>
#include <array>

class Hangar {
private:
    std::mutex zonas[5];
public:
    std::mutex& getZona(int i);
};

#endif //HANGAR_HPP