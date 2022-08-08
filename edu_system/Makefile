CC=gcc
BIN=edu_system.bin
OBJ=main.o system.o student.o teacher.o principal.o stu_func.o tea_func.o pri_func.o all_tools.o
FLAG=-Wall -Werror
STD=-std=gnu99

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) && ./$(BIN)

%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)

