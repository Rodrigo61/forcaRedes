#include "player.hpp"

void player::init_game(const string &word, int hp)
{
  gs = new game_master::game_state(word, hp);
}

player::player() {}

string player::evaluate_msg(const string &str_msg)
{
  protocol::protocol_message msg(str_msg);

  if (!gs->is_in_progress())
  {
    if (msg.is_new_game())
    {
      init_game(msg.get_init_word(), msg.get_init_hp());
      return protocol::create_init_success_msg();
    }
    else
    {
      return protocol::create_init_failure_msg();
    }
  }
  
  if (!msg.is_letter_try())
  {
    return protocol::create_confirmation_msg();
  }

  string letter = msg.get_tried_letter();

  if (game_master::valid_letter(letter))
  {
    char char_letter = letter[0];
    int res = gs->try_letter(char_letter);

    if (res == game_master::CORRECT_LETTER)
    {
      if (gs->has_won())
      {
        return protocol::create_victory_msg();
      }
      else if (gs->has_lost())
      {
        return protocol::create_lose_msg();
      }
      else
      {
        return protocol::create_right_letter_msg(gs->get_current_word());
      }
    }
    else if (res == game_master::USED_LETTER)
    {
      return protocol::create_used_letter_msg();
    }
    else
    {
      return protocol::create_wrong_letter_msg();
    }
    
  }
  else
  {
    return protocol::create_invalid_letter_msg();
  }
  
}


