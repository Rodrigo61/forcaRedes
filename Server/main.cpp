#include <arpa/inet.h>
#include "server_controller.hpp"
#include <iostream>

using namespace std;

int main (int argc, char **argv) {

  if (argc != 3) {
    cerr << "Por favor, insira uma porta e um caminho de dicionario como argumentos." << endl;
    exit(1);
  }

  int port = atoi(argv[1]);
  dictionary::init(argv[2]);
  
  server_controller::start_server(port);

}
