CXX = g++
CXXFLAGS = -std=c++11
SRC=src/*.cpp
BIN=bin
EXEC=bin/snake
OBJ=obj/*.o


all: $(EXEC)
	bin/snake

$(EXEC): $(OBJ)
	g++ -o $@ $< $(CXXFLAGS)

$(OBJ): $(SRC)
	g++ -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf $(OBJ)
	
mrproper:
	rm $(EXEC)
