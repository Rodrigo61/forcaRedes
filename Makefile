CFLAGS = -Wall -g

# Adicione aqui as libs. LIB_CODE = cpps e LIB_HEADER = hpps
LIB_CODE_ALL = protocol.cpp
LIB_HEADER_ALL = protocol.hpp

LIB_CODE_SERVIDOR = ./Servidor/Dicionario.cpp ./Servidor/game_master.cpp \
./Servidor/player.cpp ./Servidor/server_controller.hpp ./Servidor/socket_helper.hpp
LIB_HEADER_SERVIDOR = ./Servidor/Dicionario.hpp ./Servidor/game_master.hpp \
./Servidor/player.hpp ./Servidor/server_controller.hpp ./Servidor/socket_helper.hpp

LIB_CODE_CLIENTE =
LIB_HEADER_CLIENTE = 

all: cliente servidor

cliente: ./Cliente/main.cpp $(LIB_CODE_CLIENTE) $(LIB_HEADER)
	g++ $(CFLAGS) ./Cliente/main.cpp $(LIB_CODE) -o cliente

servidor: ./Servidor/main.cpp $(LIB_CODE_SERVIDOR) $(LIB_CODE_ALL) $(LIB_HEADER_SERVIDOR)  $(LIB_HEADER_ALL)
	g++ $(CFLAGS) ./Servidor/main.cpp $(LIB_CODE_SERVIDOR) $(LIB_CODE_ALL) -o servidor

.PHONY: clean
clean:
	rm -f ./Cliente/cliente ./Servidor/servidor

