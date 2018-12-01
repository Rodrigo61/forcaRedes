#include "game_master.hpp"
#include "../protocol.hpp"
#include "dictionary.hpp"

/**
 * A classe player é usada para representar o jogador cliente dentro do servidor. 
 * Ela funciona como uma interface que interpreta as mensagens recebidas pelo ser-
 * vidor do cliente, requisita atualizacao do estado do jogo e retorna em forma de
 * mensagem o proximo passo do fluxo do jogo.
 * 
 * */


class player
{
  private:
    string name;
    int wins, losses;
    game_master::game_state *gs;

    void new_game(const string &word, int hp);
    string new_game_flow(protocol::protocol_message &msg);
    string try_letter_flow(protocol::protocol_message &msg);
    string try_word_flow(protocol::protocol_message &msg);
    string unexpected_msg_flow();

  public:
    player();

    string evaluate_msg(const string &str_msg);
     
};