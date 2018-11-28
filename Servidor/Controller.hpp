#include <string>
#include <algorithm>
using namespace std;

namespace controller
{
  class GameState
  {
    private:
      int hp;
      string target_word;
      bool used_letter[255];
      
    public:
      GameState();
      void decrement_hp();
      void increment_hp();
      void get_hp();
      void reset_gamestate();
      bool try_letter(char letter);

  };

}