#include <iostream>
#include "Dicionario.hpp"

using namespace std;

int main()
{
  cout << Dicionario::get_was_init() << endl;
  Dicionario::init("oi");
  cout << Dicionario::get_was_init() << endl;

  return 0;
}