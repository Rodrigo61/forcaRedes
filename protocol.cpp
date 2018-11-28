#include "protocol.hpp"

namespace protocol
{

    enum Bytecode : char {
        NEWGAME = 1
    };
  /**********************************/
  /** BEGIN: protocol_message class**/
  /**********************************/
  protocol_message::protocol_message(const string &message)
  {
    msg = message;
  }

  bool protocol_message::is_new_game(){}
  bool protocol_message::is_letter_try(){}
  bool protocol_message::is_init_failure(){}
  bool protocol_message::is_init_success(){}
  bool protocol_message::is_invalid_letter(){}
  bool protocol_message::is_wrong_letter(){}
  bool protocol_message::is_already_used_letter(){}
  bool protocol_message::is_victory(){}
  bool protocol_message::is_defeat(){}
  bool protocol_message::is_right_letter(){}
  string protocol_message::get_tried_letter(){}
  string protocol_message::get_init_word(){}
  int protocol_message::get_init_hp(){}
  string protocol_message::which_type(){}

  /***************************/
  /** END: protocol_message **/
  /***************************/

  string create_init_failure_msg() { return "INIT_FAILURE"; }
  string create_init_success_msg() { return "INIT_SUCCESS"; }
  string create_victory_msg() { return "Você adivinhou a palavra!"; }
  string create_restart_msg() { return "RESTART"; }
  string create_unexpected_msg() {}

  string create_already_used_letter_msg(char letter) 
  { 
    stringstream ss;
    ss << "A letra '" << letter << "' já foi utilizada"; 
    return ss.str();
  }

  string create_invalid_letter_msg(char letter, int hp) 
  { 
    stringstream ss;
    ss << "O que foi enviado não é considerado uma letra válida. Certifique-se de enviar apenas um caracter simpls [a-z] ou [A-Z].\n"
         << "Você agora possui " << hp << " vidas.";
    return ss.str();
  }

  string create_wrong_letter_msg(char letter, int hp) 
  {
    stringstream ss;
    ss << "A palavra não tem nenhuma letra '" << letter << "'.\n"
         << "Você agora possui " << hp << " vidas.";
    return ss.str();
  }

  string create_right_letter_msg(const string &current_word)
  {
    return current_word;
  }

  string create_defeat_msg(int init_hp, const string &target_word) 
  {
    stringstream ss;
    ss << "Forca! Você fez " << init_hp << " tentativas incorretas...\n"
          << "A palavra correta era \"" << target_word << "\", você perdeu!\n"
          << "Deseja jogar outra partida? digite \"SIM\"";
    return ss.str();
  }

  string create_new_game_msg()
  {
    stringstream ss;
    ss << NEWGAME;
    return ss.str();
  }
  
}