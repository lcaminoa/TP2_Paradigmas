CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -IHeaders

SRCS = main.cpp Sources/Pokedex.cpp Sources/Pokemon.cpp Sources/PokemonInfo.cpp

OUT = Ej1

all: $(OUT)

$(OUT): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRCS)

clean:
	rm -f $(OUT) *.dat