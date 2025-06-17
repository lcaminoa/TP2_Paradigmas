#include "Drone.hpp"
#include "Hangar.hpp"

int main(){
    Hangar hangar; //Se incializa con los mutex para las 5 zonas automaticamente
    std::mutex mutex_out;
    std::thread despegues[5];
    Drone drones[5] = {
        Drone(0, hangar.getZonas(), &mutex_out),
        Drone(1, hangar.getZonas(), &mutex_out),
        Drone(2, hangar.getZonas(), &mutex_out),
        Drone(3, hangar.getZonas(), &mutex_out),
        Drone(4, hangar.getZonas(), &mutex_out),
    };
    for (int i = 0; i<5; ++i){
        despegues[i] = std::thread(&Drone::despegar, &drones[i]);
    }

    for (int i = 0; i<5; ++i){
        despegues[i].join();
    }
    return 0;
}
