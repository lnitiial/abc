CC=gcc
BIN=server
OBJ=wechat_tcpS.o queue.o threadpool.o
STD=-std=gnu99
FLAG=-Wall -Werror
LD=-pthread -lnw

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LD) && ./$(BIN)

%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)
	rm -rf *~ *.h.gch
