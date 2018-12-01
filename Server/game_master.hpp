#include <string>
#include <algorithm>
using namespace std;

/**
 * O namespace game_master é responsável por conhecer o comportamento do jogo e suas regras. Toda decisão
 * de jogo deve ser tomada por ele. Seu recurso principal é a classe game_state, onde cada uma de suas ins-
 * tancias conhece o estado atual do jogo de um único jogador. 
 * 
 * */

namespace game_master
{
  const int CORRECT_LETTER = 0;
  const int USED_LETTER = 1;
  const int WRONG_LETTER = 2;
  const int INIT_HP_DEFAULT = 6;
  
  class game_state
  {
    private:
      int hp;
      int init_hp;
      string target_word;
      string current_word;
      bool used_letter[255];
      bool in_progress;
      
    public:
      game_state();
      
      void new_game(const string &target_word, int init_hp);
      bool is_in_progress();
      void stop_game();
      bool has_won();
      bool has_lost();
      int try_letter(char letter);
      string get_current_word();
      string get_target_word();
      int get_init_hp();
      int get_hp();
      bool is_correct_word(const string &tried_word);

  };

  bool valid_letter(char letter);
 
}