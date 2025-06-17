#pragma once

#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>


class Drone {
private:
    int id; // Posición (de 0 a 4)
    std::mutex* zonas;
    std::mutex* mutex_out; //Para no sobreescribir en la terminal
public:
    Drone(int num, std::mutex* zones, std::mutex* out): id(num), zonas(zones), mutex_out(out) {};
    int getId() const;
    void despegar();
};