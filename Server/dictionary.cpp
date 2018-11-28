#include "dictionary.hpp"

namespace dictionary
{
  
  /*******************/
  /* Recurso privado */
  /*******************/
  namespace
  {
    bool was_init = false;
    vector<string> vet_words;

    void check_init()
    {
      if (!was_init)
      {
        cerr << "Dicionario está sendo utilizado sem ter sido propriamente iniciado pela funcao init()" << endl;
        exit(1);
      }    
    }

    // trim from start
    void left_trim(string &s) {
      s.erase(s.begin(), find_if(s.begin(), s.end(),
              not1(ptr_fun<int, int>(isspace))));
    }

    // trim from end
    void right_trim(string &s) {
      s.erase(find_if(s.rbegin(), s.rend(),
              not1(ptr_fun<int, int>(isspace))).base(), s.end());
    }

    // trim from both ends
    void trim(string &s) {
      left_trim(s);
      right_trim(s);
    }
  }

  /********************/
  /* Funcoes publicas */
  /********************/
  void init(const string &file_path)
  {
    string line;
    ifstream file(file_path);

    if (file.is_open())
    {
      vet_words.clear();

      while (getline(file, line))
      {
        trim(line);
        vet_words.push_back(line);
      }

      file.close();
      was_init = true;
    }
    else
    {
      cerr << "Impossivel abrir o arquivo de Dicionario no caminho: " << file_path << endl;
      exit(1);
    }
  }

  vector<string> get_all_words()
  {
    check_init();
    return vet_words;
  }

  string get_random_word()
  {
    check_init();
    
    srand(time(NULL)); // random seed
    int i = rand() % vet_words.size(); 
    return vet_words[i];
  }

  string get_word_by_index(int index)
  {
    return vet_words[index];
  }
}