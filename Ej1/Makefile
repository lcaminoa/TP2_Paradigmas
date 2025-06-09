# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -IHeaders

# Archivos fuente
SRCS = main.cpp Sources/Pokedex.cpp Sources/Pokemon.cpp Sources/PokemonInfo.cpp

# Nombre del ejecutable
OUT = pokedex

# Regla principal
all: $(OUT)

$(OUT): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRCS)

# Limpiar archivos generados
clean:
	rm -f $(OUT)