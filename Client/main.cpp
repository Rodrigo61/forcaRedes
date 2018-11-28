#include <arpa/inet.h>
#include <iostream>
#include "../protocol.hpp"
#include "../socket_helper.hpp"
#define HELP_SWITCH "-h"
using namespace std;

int display_main_menu();
void handle_option(int, int);
bool play_again();
int connect_to_server(char*, int);
void partida_simples(int);

int main (int argc, char **argv)
{
    int opcao;
    int server_conn_fd;

    if(argc < 3){
        cout << "Servidor/Porta não especificado, uso: forca <servidor> <porta> \n";
        exit(1);
    }

    server_conn_fd = connect_to_server(argv[1], atoi(argv[2]));

    for(;;)
    {
        opcao = display_main_menu();
        handle_option(opcao, server_conn_fd);
        if (!play_again()) break;
    }

}


int display_main_menu()
{
    int aux;
    cout << "Bem vindo ao jogo da forca!\n" << "-----\n\n";
    cout << "1) Iniciar partida simples\n";
    cout << "2) Ser carrasco ao iniciar partida\n";
    cout << "3) jogar no modo multiplayer\n";
    cin  >> aux;
    return aux;
};

void handle_option(int opcao, int connection){
    switch(opcao){
        case 1:
            partida_simples(connection);
            break;
        case 2:
//            ser_carrasco(connection);
            break;
        case 3:
//            multiplayer(connection);
            break;
    }
}

bool play_again(){
    return true;
}

int connect_to_server(char* ip, int port){
    int sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr = ClientSockaddrIn(AF_INET, ip, port);
    Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    return sockfd;
}

void partida_simples(){

}
