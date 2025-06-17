#include "../Headers/Drone.hpp"

int Drone::getId() const {
    return id;
}

void Drone::despegar() {
    int izq = (id+1)%5; // Se tomó el drone 0 con zona der 0 y zona izq 1
    int der = id;

    {
        std::lock_guard<std::mutex> lock(*mutex_out);
        std::cout << "Dron " << getId() << " esperando para despegar..." << std::endl;
    }
    
    lock(zonas[izq],zonas[der]);

    std::lock_guard<std::mutex> lado_izq(zonas[izq], std::adopt_lock);
    std::lock_guard<std::mutex> lado_der(zonas[der], std::adopt_lock);

    {
        std::lock_guard<std::mutex> lock(*mutex_out);
        std::cout << "Dron " << getId() << " despegando..." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    {
        std::lock_guard<std::mutex> lock(*mutex_out);
        std::cout << "Dron " << getId() << " alcanzo una altura de 10m" << std::endl;
    }

}