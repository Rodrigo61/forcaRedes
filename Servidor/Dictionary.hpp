#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

namespace Dictionary
{
  void init(const string &file_path);
  vector<string> get_all_words();
  string get_random_word();
  string get_word_by_index(int index);
}