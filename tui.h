#ifndef TUI_H
#define TUI_H
#include "account.h"
#include "database.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace ui{

class tui{
public:
  tui();
  int menu();
private:
  void accountmenu(std::string username);
  int process();
  void login();
  void create();
  bool paswdcheck(std::string str);
  bool usercheck(std::string str);
  std::string input;
  data::database users;
};

}

#endif
