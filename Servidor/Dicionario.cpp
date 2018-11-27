#include "Dicionario.hpp"

namespace Dicionario
{
  bool was_init = false;

  void init(const string &file_path)
  {
    was_init = true;
  }

  bool get_was_init()
  {
    return was_init;
  }
}