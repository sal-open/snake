CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g
LDFLAGS = -lncurses
SOURCES = home/*.cpp main.cpp
OUTPUT = output/snake

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
