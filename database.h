#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <sstream>
#include <string>
#include <mysql/mysql.h>

namespace data{

class database{
public:
  void adduser(std::string username, std::string password, std::string land);
  int init();
  char* getpaswd(std::string username);
  bool does_exist_user(std::string user);
  void edit_land(std::string username, std::string land);
  database();
  char* getland(std::string username);
private:
  void connect();
  MYSQL *con;
};
}
#endif
