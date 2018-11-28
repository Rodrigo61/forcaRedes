#include "game_master.hpp"
#include "../protocol.hpp"

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
    int score;
    game_master::game_state *gs;

    void init_game(const string &word, int hp);

  public:
    player();

    string evaluate_msg(const string &str_msg);
     
};