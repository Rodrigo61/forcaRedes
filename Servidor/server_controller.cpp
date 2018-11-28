#include "server_controller.hpp"

#define LISTENQ 10
#define BUFFER_SZ 4096

namespace server_controller
{
  namespace
  {
    int listenfd;
    char buffer[BUFFER_SZ]                  ;
    struct sockaddr_in servaddr;  
    set<int> set_connfd; 
    map<int, player*> connfd_to_player;
    fd_set rset;

    void add_new_player(int connfd)
    {
      set_connfd.insert(connfd);
      connfd_to_player[connfd] = new player();
    }

    void evaluate_welcome_socket()
    {
      if (FD_ISSET(listenfd, &rset))
      {
        struct sockaddr_in playeraddr;
        socklen_t playeraddr_len = sizeof(playeraddr);
        int connfd = Accept(listenfd, (struct sockaddr *) &playeraddr, &playeraddr_len);

        add_new_player(connfd);
      }
    }

    void set_welcome_socket_to_IO_multiplex()
    {
      FD_SET(listenfd, &rset);
    }

    void reset_IO_multiplex()
    {
      FD_ZERO(&rset);
    }

    void evalute_player_msg(int connfd, const string &msg)
    {
      player *p = connfd_to_player[connfd];
      p->evaluate(msg);
    }

    void erase_player (int connfd)
    {
      set_connfd.erase(connfd);
      connfd_to_player.erase(connfd);
    }

    void evaluate_players_IO()
    {
      for (int connfd : set_connfd)
      {
        if (FD_ISSET(connfd, &rset))
        {
          int msg_sz = read(connfd, buffer, BUFFER_SZ);
          
          if (msg_sz == 0)
          {
            // Player fechou conexao TCP.
            erase_player(connfd);
          }
          else{
            buffer[msg_sz] = 0;
            string response = evalute_player_msg(buffer);
            // Envia ação de resposta do servidor
            write(connfd, response.c_str(), response.size());
          }
        }
      }
    }

    void set_players_to_IO_multiplex()
    {
      for (int connfd : set_connfd)
      {
        FD_SET(connfd, &rset);
      }
    }

    void IO_multiplex_loop()
    {
      while (true)
      {
        set_welcome_socket_to_IO_multiplex();
        set_players_to_IO_multiplex();
        
        /* Ativando o select de leitura*/
        int maxfdp1 = max(listenfd, *max_element(set_connfd));
        select(maxfdp1 + 1, &rset, NULL, NULL);
        
        /* Tratando os descriptors que estão sendo monitorados */
        evaluate_players_IO();
        evaluate_welcome_socket();
      }
    }

    void init_welcome_socket(int port)
    {
      listenfd = Socket(AF_INET, SOCK_STREAM, 0);
      servaddr = ServerSockaddrIn(AF_INET, INADDR_ANY, port);
      Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
      Listen(listenfd, LISTENQ);
    }
  }

  void start_server(int port)
  {
    reset_IO_multiplex();
    init_welcome_socket(port);
    IO_multiplex_loop();
  }

}