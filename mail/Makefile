CC=gcc
BIN=mail
OBJ=main.o sub.o tool.o
STD=-std=gnu99
FLAG=-Wall -Werror
LD=-lm
INCLUDE=-I.

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LD)

%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)
