#include "server_controller.hpp"

#define LISTENQ 10
#define BUFFER_SZ 4096

namespace server_controller
{
  namespace
  {
    int listenfd;
    char buffer[BUFFER_SZ];
    struct sockaddr_in servaddr;  
    set<int> set_connfd; 
    map<string, player*> ip_to_player;
    map<int, string> connfd_to_ip;
    fd_set rset;

    void add_new_player(int connfd, string ip)
    {
      set_connfd.insert(connfd);
      connfd_to_ip[connfd] = ip;

      if (ip_to_player.find(ip) == ip_to_player.end())
      {
        cout << ip << " inédito ao servidor foi conectado." << endl;
        ip_to_player[ip] = new player();
      }   
      else
      {
        cout << ip << " conectado ao servidor." << endl;
      }
      
    }

    void evaluate_welcome_socket()
    {
      if (FD_ISSET(listenfd, &rset))
      {
        cout << "Novo jogador" << endl;
        struct sockaddr_in playeraddr;
        socklen_t playeraddr_len = sizeof(playeraddr);
        int connfd = Accept(listenfd, (struct sockaddr *) &playeraddr, &playeraddr_len);
        string ip = Get_IP(&playeraddr);
        add_new_player(connfd, ip);
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

    string evaluate_player_msg(int connfd, char *msg)
    {
      string ip = connfd_to_ip[connfd];
      player *p = ip_to_player[ip];
      return p->evaluate_msg(msg);
    }

    void disconnect_player (int connfd)
    {
      if (connfd_to_ip.find(connfd) != connfd_to_ip.end())
      {
        string ip = connfd_to_ip[connfd];
        cout << ip << " foi desconectado." << endl;
        player *p = ip_to_player[ip];
        p->disconnect();
        connfd_to_ip.erase(connfd);
      }
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
            disconnect_player(connfd);
          }
          else{
            buffer[msg_sz] = 0;
            string response = evaluate_player_msg(connfd, buffer);
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
        int maxfdp1 = listenfd;
        if (!set_connfd.empty())
        {
          maxfdp1 = max(maxfdp1, *set_connfd.rbegin());
        }
        select(maxfdp1 + 1, &rset, NULL, NULL, 0);
        
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