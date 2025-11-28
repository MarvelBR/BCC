CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Iinclude
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=build/%.o)
BIN := build/indice

.PHONY: all clean run

all: $(BIN)

build:
	mkdir -p build

$(BIN): build $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf build
