#include "game_master.hpp"

namespace game_master
{
  
  game_state::game_state(const string &word, int init_hp)
  {
    target_word = word;
    current_word = target_word;
    fill(current_word.begin(), current_word.end(), '_');
    fill(used_letter, used_letter + 255, 0);
    this->init_hp = hp = init_hp;
  }

  bool game_state::is_in_progress()
  {
    return in_progress;
  }

  bool game_state::has_won()
  {
    for (char c : target_word)
    {
      if (!used_letter[(int)c])
      {
        return false;
      }
    }

    return true;
  }

  bool game_state::has_lost()
  {
    return hp == 0;
  }

  int game_state::try_letter(char letter)
  {
    if (used_letter[(int)letter])
    {
      return USED_LETTER;
    }
    if (target_word.find(letter) == string::npos)
    {
      --hp;
      return WRONG_LETTER;
    }

    used_letter[(int)letter] = true;
    for (int i = 0; i < (int)target_word.size(); ++i)
    {
      if (target_word[i] == letter)
      {
        current_word[i] = letter;
      }
    }

    return CORRECT_LETTER;

  }

  string game_state::get_current_word()
  {
    return current_word;
  }

  bool valid_letter(const string &letter)
  {
    if (letter.size() != 1)
    {
      return false;
    }

    return isalpha(letter[0]);
  }
}