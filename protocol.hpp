#include <string>
#include <sstream>

using namespace std;

namespace protocol
{
  enum Bytecode : char {
    NEWGAME = 1
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
      
      string to_string();
      bool is_new_game();
      bool is_letter_try();
      bool is_init_failure();
      bool is_init_success();
      bool is_invalid_letter();
      bool is_wrong_letter();
      bool is_already_used_letter();
      bool is_victory();
      bool is_defeat();
      bool is_right_letter();
      string get_tried_letter();
      string get_init_word();
      int get_init_hp();
      string which_type();
      
    
  };

  string create_init_failure_msg();
  string create_init_success_msg();
  string create_victory_msg();
  string create_defeat_msg();
  string create_already_used_letter_msg();
  string create_invalid_letter_msg();
  string create_reinit_msg();
  string create_confirmation_msg();
  string create_right_letter_msg(const string &current_word);
  string create_used_letter_msg();
  string create_wrong_letter_msg();
  string create_unexpected_msg();
  string create_new_game_msg();
  
}