#include <arpa/inet.h>
#include "server_controller.hpp"
#include <iostream>

using namespace std;

int main (int argc, char **argv) {

  if (argc != 2) {
    cerr << "Por favor, insira uma porta como argumento." << endl;
    exit(1);
  }

  int port = atoi(argv[1]);

  server_controller::start_server(port);

}
