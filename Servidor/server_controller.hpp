#include <arpa/inet.h>
#include "basic.h"
#include "socket_helper.hpp"
#include <set>

/**
 * O namespace server_controller é responsável por conter as funções de gerencia de rede do servidor.
 * Ele é responsável pelas conexões TCP e a multiplexação de IO dessas conexões. Ele utiliza instancias
 * da classe Player para representar cada jogador, esse estando associado a uma única conexão TCP.
 */ 

namespace server_controller
{
  void start_server(int port);
}