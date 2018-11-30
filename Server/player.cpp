#include "player.hpp"

void player::init_game(const string &word, int hp)
{
  gs = new game_master::game_state(word, hp);
}

player::player() {}

string player::new_game_flow(protocol::protocol_message &msg)
{
  if (gs->is_in_progress())
  {
    return protocol::create_new_game_failure_msg();
  }
  
  init_game(dictionary::get_random_word(), game_master::INIT_HP_DEFAULT);

  return protocol::create_new_game_success_msg();  
}

string player::try_letter_flow(protocol::protocol_message &msg)
{
  char letter = msg.get_tried_letter();

  if (game_master::valid_letter(letter))
  {
    int res = gs->try_letter(letter);

    if (res == game_master::CORRECT_LETTER)
    {
      if (gs->has_won())
      {
        score++;
        return protocol::create_victory_msg();
      }
      else if (gs->has_lost())
      {
        return protocol::create_defeat_msg(gs->get_init_hp(), gs->get_target_word());
      }
      else
      {
        return protocol::create_right_letter_msg(gs->get_current_word());
      }
    }
    else if (res == game_master::USED_LETTER)
    {
      return protocol::create_used_letter_msg(letter);
    }
    else
    {
      return protocol::create_wrong_letter_msg(letter, gs->get_hp());
    }

  }
  else
  {
    return protocol::create_invalid_letter_msg(letter, gs->get_hp());
  }
  
}

string player::unexpected_msg_flow()
{
  return protocol::create_unexpected_msg();
}

string player::evaluate_msg(const string &str_msg)
{

  protocol::protocol_message msg(str_msg);

  if (msg.is_new_game())
  {
    return new_game_flow(msg);
  }
  
  if (msg.is_letter_try())
  {
    return try_letter_flow(msg);
  }
  
  return unexpected_msg_flow();
}


