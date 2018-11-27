CFLAGS = -Wall -g

# Adicione aqui as libs. LIB_CODE = cpps e LIB_HEADER = hpps
LIB_CODE_SERVIDOR = ./Servidor/Dictionary.cpp
LIB_HEADER_SERVIDOR = ./Servidor/Dictionary.hpp

LIB_CODE_CLIENTE =
LIB_HEADER_CLIENTE = 

all: cliente servidor

cliente: ./Cliente/main.cpp $(LIB_CODE) $(LIB_HEADER)
	g++ $(CFLAGS) ./Cliente/main.cpp $(LIB_CODE) -o cliente

servidor: ./Servidor/main.cpp $(LIB_CODE_SERVIDOR) $(LIB_HEADER_SERVIDOR)
	g++ $(CFLAGS) ./Servidor/main.cpp $(LIB_CODE_SERVIDOR) -o servidor

.PHONY: clean
clean:
	rm -f ./Cliente/cliente ./Servidor/servidor

