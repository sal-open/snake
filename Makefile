CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -I. -Igame
LDFLAGS = -lncurses
SOURCES = home/*.cpp score/*.cpp utilities.cpp main.cpp  game/*.cpp game/*.hpp
OUTPUT = output/snake

all:
	mkdir -p output
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
