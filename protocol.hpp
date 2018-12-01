#include <string>
#include <sstream>
#include <iostream>

using namespace std;

namespace protocol
{
  enum Bytecode : char {
    NEW_GAME = 1,
    NEW_GAME_SUCCESS,
    NEW_GAME_FAILURE,
    TRY_LETTER,
    INVALID_LETTER,
    WRONG_LETTER,
    USED_LETTER,
    TRY_WORD,
    VICTORY,
    DEFEAT_BY_NO_HP,
    DEFEAT_BY_WRONG_WORD,
    RIGHT_LETTER,
    UNEXPECTED
  };

  class protocol_message
  {
    string msg;
    int type;
    string parameter;

    char extract_type(const string &raw_message);
    string extract_parameter(const string &raw_message);

    public:

      protocol_message(const string &raw_message);
      protocol_message();

      string to_string();
      char get_tried_letter();
      int get_type();
      string get_parameter();
      bool is_new_game();
      bool is_try_letter();
      bool is_try_word();
      bool is_new_game_success();
      bool is_new_game_failure();
      bool is_invalid_letter();
      bool is_wrong_letter();
      bool is_used_letter();
      bool is_victory();
      bool is_defeat_by_no_hp();
      bool is_defeat_by_wrong_word();
      bool is_right_letter();
  };

  string create_new_game_success_msg(const string &create_new_game_success_msg);
  string create_new_game_failure_msg();
  string create_victory_msg(const string &target_word, int wins, int losses);
  string create_defeat_by_no_hp_msg(int init_hp, const string &target_word, int wins, int losses);
  string create_defeat_by_wrong_word_msg(const string &tried_word, const string &target_word, int wins, int losses);
  string create_already_used_letter_msg();
  string create_invalid_letter_msg(char letter, int hp);
  string create_confirmation_msg();
  string create_right_letter_msg(const string &current_word);
  string create_used_letter_msg(char letter);
  string create_wrong_letter_msg(char letter, int hp);
  string create_unexpected_msg();
  string create_new_game_msg();
  string create_try_letter_msg(char);
  string create_try_word_msg(string);
}