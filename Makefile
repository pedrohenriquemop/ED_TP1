CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/BinaryTree.o $(OBJ)/Expression.o $(OBJ)/Utils.o
HDRS = $(INC)/BinaryTree.hpp $(INC)/Expression.hpp $(INC)/Stack.hpp $(INC)/Utils.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp

$(OBJ)/Expression.o: $(HDRS) $(SRC)/Expression.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Expression.o $(SRC)/Expression.cpp

$(OBJ)/Utils.o: $(HDRS) $(SRC)/Utils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Utils.o $(SRC)/Utils.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out