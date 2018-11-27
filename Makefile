CFLAGS = -Wall -g

# Adicione aqui as libs. LIB_CODE = cpps e LIB_HEADER = hpps
LIB_CODE = 
LIB_HEADER = 

all: cliente servidor

cliente: cliente.c $(LIB_CODE) $(LIB_HEADER)
	gcc $(CFLAGS) cliente.c $(LIB_CODE) -o cliente

servidor: servidor.c $(LIB_CODE) $(LIB_HEADER)
	gcc $(CFLAGS) servidor.c $(LIB_CODE) -o servidor

.PHONY: clean
clean:
	rm -f cliente servidor

