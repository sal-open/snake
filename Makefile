CXX = g++
CXXFLAGS = -std=c++17 -fdiagnostics-color=always -g -I.
LDFLAGS = -lncurses
SOURCES = game/*.cpp home/*.cpp score/*.cpp utilities.cpp main.cpp
OUTPUT = ./output

all:
	mkdir -p $(OUTPUT)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)/snake $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
