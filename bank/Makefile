CC=gcc
STD=-std=gnu99
FLAG=-Wall -Werror
BIN=open destory login unlock save take modify transfer	query
TARGE=Server Client
RELY=bank.h Cli_tools.c Cli_tools.h

all:$(BIN) $(TARGE)
	mv $(BIN) ./bin
	./Server

%:%.c $(RELY)
	$(CC) $(STD) $(FLAG) Cli_tools.c $< -o $@

	
clean:
	cd ./bin && rm -rf $(BIN)
	rm -rf $(TARGE)
	rm -rf *.o
	rm -rf *~ *.h.gch

