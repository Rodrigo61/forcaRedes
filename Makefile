CFLAGS = -Wall -g

# Adicione aqui as libs. LIB_CODE = cpps e LIB_HEADER = hpps
LIB_CODE_ALL = ./protocol.cpp ./socket_helper.cpp
LIB_HEADER_ALL = ./protocol.hpp ./socket_helper.hpp

LIB_CODE_SERVER = ./Server/dictionary.cpp ./Server/game_master.cpp \
./Server/player.cpp ./Server/server_controller.cpp
LIB_HEADER_SERVER = ./Server/dictionary.hpp ./Server/game_master.hpp \
./Server/player.hpp ./Server/server_controller.hpp

LIB_CODE_CLIENT =
LIB_HEADER_CLIENT = 

all: Client Server

client: ./Client/main.cpp $(LIB_CODE_CLIENT) $(LIB_CODE_ALL) $(LIB_HEADER_CLIENT)  $(LIB_HEADER_ALL)
	g++ $(CFLAGS) ./Client/main.cpp $(LIB_CODE_CLIENT) $(LIB_CODE_ALL) -o client

server: ./Server/main.cpp $(LIB_CODE_SERVER) $(LIB_CODE_ALL) $(LIB_HEADER_SERVER)  $(LIB_HEADER_ALL)
	g++ $(CFLAGS) ./Server/main.cpp $(LIB_CODE_SERVER) $(LIB_CODE_ALL) -o server

.PHONY: clean
clean:
	rm -f client server

