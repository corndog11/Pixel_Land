#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "database.h"
#include <string>
#include <iostream>

namespace ac{
class account{
public:
account(std::string username);
void menu();
private:
  int process();
  std::string m_username;
  std::string m_comd;
  data::database users;
};
}

#endif