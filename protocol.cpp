#include "protocol.hpp"

namespace protocol
{
  
  /**********************************/
  /** BEGIN: protocol_message class**/
  /**********************************/

  char protocol_message::extract_type(const string &raw_message)
  {
    return (char)raw_message[0];
  }

  string protocol_message::extract_parameter(const string &raw_message)
  {
    return string(raw_message.begin() + 1, raw_message.end());
  }

  protocol_message::protocol_message() {}

  protocol_message::protocol_message(const string &message)
  {
    msg = message;
    parameter = extract_parameter(message);
    type = extract_type(message);
  }
  
  string protocol_message::to_string()
  {
    stringstream ss;
    ss << "Tipo = " << type << " Parametro = " << parameter;
    return ss.str();
  }

  int protocol_message::get_type() 
  { 
    return type; 
  }

  char protocol_message::get_tried_letter()
  {
    return parameter[0]; // converto para char pegando apenas o primeiro char da string de parametro
  }

  string protocol_message::get_parameter()
  {
    return parameter;
  }
  
  bool protocol_message::is_new_game() { return type == NEW_GAME; }
  bool protocol_message::is_letter_try() { return type == TRY_LETTER; }
  bool protocol_message::is_new_game_failure() { return type == NEW_GAME_FAILURE; }
  bool protocol_message::is_new_game_success() { return type == NEW_GAME_SUCCESS; }
  bool protocol_message::is_invalid_letter() { return type == INVALID_LETTER; }
  bool protocol_message::is_wrong_letter() { return type == WRONG_LETTER; }
  bool protocol_message::is_used_letter() { return type == USED_LETTER; }
  bool protocol_message::is_victory() { return type == VICTORY; }
  bool protocol_message::is_defeat() { return type == DEFEAT; }
  bool protocol_message::is_right_letter() { return type == RIGHT_LETTER; }
  bool protocol_message::is_send_letter() { return type == TRY_LETTER; }
  
  /***************************/
  /** END: protocol_message **/
  /***************************/
  
  string create_new_game_failure_msg() 
  { 
    stringstream ss;
    ss << (char)NEW_GAME_FAILURE;
    return ss.str();
  }
  
  string create_new_game_success_msg(const string &current_word) 
  { 
    stringstream ss;
    ss << (char)NEW_GAME_SUCCESS;
    ss << current_word << endl;
    return ss.str();
  }

  string create_send_letter_msg(char letter) {
    stringstream ss;
    ss << (char)TRY_LETTER;
    ss << letter;
    return ss.str();
  };

  string create_victory_msg(const string &target_word) 
  { 
    stringstream ss;
    ss << (char)VICTORY
       << "Você adivinhou a palavra '" << target_word << "'! Parabéns!\n"
       << "Deseja jogar outra partida, digite \"SIM\"\n";

    return ss.str();
  }

  string create_unexpected_msg() 
  {
    stringstream ss;
    ss << (char)UNEXPECTED;
    return ss.str();
  }

  string create_used_letter_msg(char letter) 
  { 
    stringstream ss;
    ss << (char)USED_LETTER;
    ss << "A letra '" << letter << "' já foi utilizada"; 
    return ss.str();
  }

  string create_invalid_letter_msg(char letter, int hp) 
  { 
    stringstream ss;
    ss << (char)INVALID_LETTER;
    ss << "O que foi enviado não é considerado uma letra válida. Certifique-se de enviar apenas um caracter simpls [a-z] ou [A-Z].\n"
       << "Você agora possui " << hp << " vidas.";
    return ss.str();
  }

  string create_wrong_letter_msg(char letter, int hp) 
  {
    stringstream ss;
    ss << (char)WRONG_LETTER;
    ss << "A palavra não tem nenhuma letra '" << letter << "'.\n"
       << "Você agora possui " << hp << " vidas.";
    return ss.str();
  }

  string create_right_letter_msg(const string &current_word)
  {
    stringstream ss;
    ss << (char)RIGHT_LETTER;
    ss << current_word;
    return ss.str();
  }

  string create_defeat_msg(int init_hp, const string &target_word) 
  {
    stringstream ss;
    ss << (char)DEFEAT;
    ss << "Forca! Você fez " << init_hp << " tentativas incorretas...\n"
       << "A palavra correta era \"" << target_word << "\", você perdeu!\n"
       << "Deseja jogar outra partida? digite \"SIM\"";
    return ss.str();
  }

  string create_new_game_msg()
  {
    stringstream ss;
    ss << (char)NEW_GAME;
    return ss.str();
  }
}