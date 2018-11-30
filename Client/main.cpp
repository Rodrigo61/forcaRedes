#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include "../protocol.hpp"
#include "../socket_helper.hpp"
#define HELP_SWITCH "-h"
#define MAX_BUFFER_LEN 4096
using namespace std;

int display_main_menu();
void handle_option(int, int);
bool play_again();
int connect_to_server(char*, int);
void simple_match(int);
void simple_match_loop(int);
void print_game_screen(string);
protocol::protocol_message send_message_to_server(int, string);

char BUFFER[MAX_BUFFER_LEN];
bool LETTERS[255];

int main (int argc, char **argv)
{
    int opcao;
    int server_conn_fd;

    if(argc < 3){
        cout << "Servidor/Porta não especificado, uso: forca <servidor> <porta>" << endl;
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
    cout << "3) jogar no modo multiplayer" << endl;
    cin  >> aux;
    return aux;
};

void handle_option(int opcao, int connection){
    switch(opcao){
        case 1:
            simple_match(connection);
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

void simple_match(int connection){
    protocol::protocol_message msg = send_message_to_server(connection, protocol::create_new_game_msg());

    if (msg.is_init_success()) {
        simple_match_loop(connection, msg.get_target_word());
    } else {
        cerr << "Não foi possível iniciar um jogo no servidor!" << endl;
    }
}

void simple_match_loop(int connection, string target_word){
    fill(LETTERS, LETTERS+255, false);
    char letter;
    string send_msg;
    protocol::protocol_message rcv_msg;
    for (;;) {
        print_game_screen(target_word);
        cin >> letter;
        send_msg = protocol::create_send_letter_msg(toupper(letter));
        rcv_msg = send_message_to_server(connection, send_msg);
        if (rcv_msg.is_right_letter()){
            //Do something
        } else if (rcv_msg.is_wrong_letter()){
            //Do stuff
        } else if (rcv_msg.is_used_letter()){
            //Do more stuff
        } else if (rcv_msg.is_defeat()){
            //Perdeu
        } else if (rcv_msg.is_victory()){
            //Ganhou
        } else if (rcv_msg.is_invalid_letter()){
            //É Burro
        } else {
            cerr << "Oops! Algo inesperado aconteceu ao enviar uma letrar para o servidor!" << endl;
            return;
        }
    }
}

void print_game_screen(string target_word){

}

protocol::protocol_message send_message_to_server(int connection, string message){
    write(connection, message.c_str(), message.size());
    read(connection, BUFFER, MAX_BUFFER_LEN);
    string recv_str = BUFFER;
    protocol::protocol_message msg(recv_str);
    return msg;
}