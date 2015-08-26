CXX = g++
CXXFLAGS = -std=c++11 -lsfml-window -lsfml-graphics -lsfml-system
BIN=bin
EXEC=bin/snake
OBJ=$(SRC:.cpp=.o)


all: $(EXEC)
	bin/snake

$(EXEC): src/*.hpp src/*.cpp
	g++ $^ -o $@ $(CXXFLAGS)

clean:
	rm -rf $(OBJ)
	
mrproper:
	rm $(EXEC)
