#include <string>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>


struct Tarea {
    int idSensor;
    int idTarea;
    std::string descripcionTarea;

    Tarea(int newIdSensor, int newIdTarea, std::string newDescripcion)
        : idSensor(newIdSensor), idTarea(newIdTarea), descripcionTarea(newDescripcion) {}
};

std::queue<Tarea> colaTareas;
std::mutex mtxCola;
std::condition_variable cvTareas;
bool sensoresFinalizados = false;
std::mutex mutex_out;

void sensor(int idSensor, int cantidadTareas) {
    for (int i = 0; i < cantidadTareas; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(175));
        Tarea t(idSensor, i, "Tarea número " + std::to_string(i));
        
        {
            std::lock_guard<std::mutex> lock(mtxCola);
            colaTareas.push(t);
        }

        {
            std::lock_guard<std::mutex> lock(mutex_out);
            cvTareas.notify_one(); //Para evitar que se notifique a un robot antes de que se llegue a imprimir que se generó la tarea
            std::cout << "[Sensor " << idSensor << "] Generó tarea " << i << "\n";
        }
    }
}

void robot(int idRobot) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtxCola);

        while (colaTareas.empty() && !sensoresFinalizados) {
            cvTareas.wait(lock);
        }

        if (!colaTareas.empty()) {
            Tarea t = colaTareas.front();
            colaTareas.pop();
            lock.unlock();

            {
                std::lock_guard<std::mutex> lock(mutex_out);
                std::cout << "[Robot " << idRobot << "] Procesando tarea de Sensor "
                        << t.idSensor << ", ID " << t.idTarea << "\n";
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        } else if (sensoresFinalizados) {
            break;
        }
    }
}

int main() {
    const int cantidadSensores = 3;
    const int cantidadRobots = 3;
    const int tareasPorSensor = 5;

    std::vector<std::thread> sensores;
    std::vector<std::thread> robots;

    for (int i = 0; i < cantidadSensores; ++i)
        sensores.emplace_back(sensor, i, tareasPorSensor);

    for (int i = 0; i < cantidadRobots; ++i)
        robots.emplace_back(robot, i);

    for (auto& s : sensores) s.join();

    {
        std::lock_guard<std::mutex> lock(mtxCola);
        sensoresFinalizados = true;
    }

    cvTareas.notify_all();

    for (auto& r : robots) r.join();

    std::cout << "Todos los robots han terminado.\n";
    return 0;
}
