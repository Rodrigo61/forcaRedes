#include "Controller.hpp"

namespace controller
{
  class game_state
  {
    private:
      int hp;
      int init_hp;
      string target_word;
      bool used_letter[255];
      
    public:
      
      game_state(string &word, int init_hp)
      { 
        target_word = word;
        fill(used_letter, used_letter + 255, 0);
        this->init_hp = hp = init_hp;
      }

      bool finished();
      bool victory();
      bool try_letter(char letter);

  };

  class connected_player
  {
    public:
      virtual char get_next_letter() = 0;
      virtual void notify_successful_letter() = 0;
      virtual void notify_unsuccessful_letter() = 0;
      virtual void notify_victory() = 0;
      virtual void notify_defeated() = 0;

  };


  void play(game_state &gs, connected_player &player)
  {
    
    while (!gs.finished())
    {
      char letter = player.get_next_letter();

      if (gs.try_letter(letter))
      {
        player.notify_successful_letter();
      }
      else
      {
        player.notify_unsuccessful_letter();
      }
    }
    
    if (gs.victory())
    {
      player.notify_victory();
    }
    else
    {
      player.notify_defeated();
    }

  }



}