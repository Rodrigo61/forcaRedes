#include <string>
#include <sstream>

using namespace std;

namespace protocol
{
  enum Bytecode : char {
    NEW_GAME,
    NEW_GAME_SUCCESS,
    NEW_GAME_FAILURE,
    SEND_LETTER,
    TRY_LETTER,
    INVALID_LETTER,
    WRONG_LETTER,
    USED_LETTER,
    VICTORY,
    DEFEAT,
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
      bool is_letter_try();
      bool is_new_game_success();
      bool is_new_game_failure();
      bool is_invalid_letter();
      bool is_wrong_letter();
      bool is_used_letter();
      bool is_victory();
      bool is_defeat();
      bool is_right_letter();
      bool is_send_letter();
  };

  string create_new_game_success_msg();
  string create_new_game_failure_msg();
  string create_victory_msg();
  string create_defeat_msg(int init_hp, const string &target_word);
  string create_already_used_letter_msg();
  string create_invalid_letter_msg(char letter, int hp);
  string create_confirmation_msg();
  string create_right_letter_msg(const string &current_word);
  string create_used_letter_msg(char letter);
  string create_wrong_letter_msg(char letter, int hp);
  string create_unexpected_msg();
  string create_new_game_msg();
  string create_send_letter_msg(char);
}