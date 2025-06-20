#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"

int main() {
    Pokedex miPokedex;

    Pokemon squirtle("Squirtle", 100);
    PokemonInfo infoSquirtle(
        "Agua",
        "Una tortuga pequeña que lanza chorros de agua.",
        {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}},
        {0, 400, 1000}
    );

    Pokemon bulbasaur("Bulbasaur", 270);
    PokemonInfo infoBulbasaur(
        "Planta",
        "Tiene una semilla en su lomo que crece con el tiempo",
        {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}},
        {0, 300, 1100}
    );

    Pokemon charmander("Charmander", 633);
    PokemonInfo infoCharmander(
        "Fuego",
        "Una lagartija con una llama en su cola",
        {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}},
        {0, 250, 1300}
    );

    miPokedex.agregar(squirtle, infoSquirtle);
    miPokedex.agregar(bulbasaur, infoBulbasaur);
    miPokedex.agregar(charmander, infoCharmander);

    miPokedex.mostrarTodos();

    std::cout << "--------------------------------------\n";
    std::cout << "Testing función mostrar():\n";
    Pokedex miPokedex2;
    Pokemon squirtle2("Squirtle", 870);
    PokemonInfo infoSquirtle2(
        "Agua",
        "Una tortuga pequeña que lanza chorros de agua.",
        {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}},
        {0, 400, 1000}
    );
    miPokedex2.agregar(squirtle2, infoSquirtle2);

    miPokedex2.mostrar(Pokemon("Squirtle", 870));
    std::cout << "-------------------------\n";
    miPokedex2.mostrar(Pokemon("Pikachu", 390));

    std::cout << "--------------------------------------\n";
    std::cout << "Testing de serialización y deserialización:\n";


    Pokedex pokedexSerializada("pokedex_test.dat");
    pokedexSerializada.agregar(squirtle, infoSquirtle);
    pokedexSerializada.agregar(bulbasaur, infoBulbasaur);
    pokedexSerializada.agregar(charmander, infoCharmander);

    Pokedex pokedexDeserializada("pokedex_test.dat");
    pokedexDeserializada.mostrarTodos();

    return 0;
}
