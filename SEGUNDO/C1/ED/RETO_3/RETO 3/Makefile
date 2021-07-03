SRC = src
INC = include
DOC = doc/doxy
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/reto3

#**********************Generación de documentación**********************#
documentacion:
		doxygen ./doc/doxy/Doxyfile.doxy

#*******************Compilación de módulos********************#

$(BIN)/reto3: $(OBJ)/reto3.o
	$(CXX) -o $(BIN)/reto3 $(OBJ)/reto3.o

$(OBJ)/reto3.o: $(SRC)/main.cpp $(INC)/cola.h $(INC)/cola.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/reto3.o

#************Limpieza************#

clean:	
	-rm $(OBJ)/*	

mrproper:
	-rm $(OBJ)/*
	-rm $(BIN)/*
	-rm -r $(DOC)/html $(DOC)/latex
