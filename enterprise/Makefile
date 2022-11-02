CC=g++
BIN=system
OBJ=main.o department.o emis.o employee.o manage.o manager_ctrl_impl.o manager_mode_impl.o manager_view_impl.o service_ctrl_impl.o service_mode_impl.o service_view_impl.o tools.o
FLAG=-Wall -Werror
STD=-std=c++0x -lmysqlclient

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)  && ./$(BIN)

%.o:%.cpp
	$(CC) $(STD)  -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)
	rm -rf *~ *.h.gch
