CC=gcc
BIN=Ftp
OBJ=main.o ftp_cli.o tools.o
STD=-std=gnu99
FLAG=-Wall -Werror
LD=-lm
INCLUDE=-I.

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LD) && ./$(BIN) 172.20.10.11

%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)
	rm -rf *~
