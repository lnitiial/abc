CC=g++
BIN=hotel
OBJ=hotel.o main.o tools.o
FLAG=-Wall -Werror
STD=-std=c++0x

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)  && ./$(BIN)

%.o:%.cpp
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)
	rm -rf *~ *.h.gch
