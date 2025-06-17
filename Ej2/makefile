CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall -Wextra -IHeaders
SRC = Ej2.cpp Sources/Drone.cpp Sources/Hangar.cpp
TARGET = Ej2

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)