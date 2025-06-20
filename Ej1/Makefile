CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -IHeaders

SRCS = Ej1.cpp Sources/Pokedex.cpp Sources/Pokemon.cpp Sources/PokemonInfo.cpp

OUT = Ej1

all: $(OUT)

$(OUT): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRCS)

clean:
	rm -f $(OUT) *.dat