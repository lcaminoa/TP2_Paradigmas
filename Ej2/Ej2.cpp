#include <mutex>
#include <thread>

class Hangar {
private:
    std::mutex zonas[5];
public:
    std::mutex& getZona(int i) {
        return zonas[i];
    }
};

class Drone {
private:
    int id; // Posición (de 0 a 4)
    std::mutex* zonas;
public:
    int getId() const {
        return id;
    }
    void despegar() {
        int izq = (id+1)%5; // Se tomó el drone 0 con zona der 0 y zona izq 1
        int der = id;


    }
};