#include "database.h"

namespace data{

database::database(){}

void database::adduser(std::string username, std::string password, std::string land){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "INSERT INTO users VALUES (" << "'" << username << "'" << "," << "'" << password <<"'" << "," << "'" << land << "'"<< ")";
  std::string insert;
  insert = ss.str();
  const char * c = insert.c_str();
  mysql_query(con, c);
  mysql_close(con);
}
int database::init(){
  connect();
  mysql_query(con, "USE users");
  mysql_query(con, "CREATE TABLE IF NOT EXISTS users(paswd TEXT, username TEXT, land TEXT, landx INT, landy INT)");

  mysql_close(con);
  return 0;
}
char* database::getpaswd(std::string username){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "SELECT paswd FROM users WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char * c = insert.c_str();
  mysql_query(con, c);
  MYSQL_RES *result;
  result = mysql_store_result(con);
  MYSQL_ROW row;
  row = mysql_fetch_row(result);
  if(row == NULL){
    std::cout << "NO USER OF THAT USERNAME" << std::endl;
    return "NOT VALID USERNAME";
  }
  mysql_free_result(result);
  mysql_close(con);
  return row[0];
}
bool database::does_exist_user(std::string user){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "SELECT username FROM users WHERE username=" << "'" << user << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  MYSQL_RES *result;
  result = mysql_store_result(con);
  MYSQL_ROW row;
  row = mysql_fetch_row(result);
  if(row == NULL){
    mysql_free_result(result);
    return false;
  }
  else{
    mysql_free_result(result);
    return true;
  }
  std::cout << "username taken" << std::endl;
  return true;
}
void database::edit_land(std::string username, std::string land){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "UPDATE users SET land=" << "'" << land << "' " << "WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  mysql_close(con);
}
void database::edit_landx(std::string username, int land){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "UPDATE users SET landx=" << land << " WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  mysql_close(con);
}
void database::edit_landy(std::string username, int land){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "UPDATE users SET landy=" << land << " WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  mysql_close(con);
}
char* database::getland(std::string username){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "SELECT land FROM users WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  MYSQL_RES *result;
  result = mysql_store_result(con);
  MYSQL_ROW row;
  row = mysql_fetch_row(result);
  if(row == NULL){
    std::cout << "ERROE ME BOI" << std::endl;
    return "ERROR";
  }
  mysql_close(con);
  mysql_free_result(result);
  return row[0];
}
char* database::getlandY(std::string username){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "SELECT landy FROM users WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  MYSQL_RES *result;
  result = mysql_store_result(con);
  MYSQL_ROW row;
  row = mysql_fetch_row(result);
  if(row == NULL){
    std::cout << "ERROE ME BOI" << std::endl;
    return "ERROR";
  }
  mysql_close(con);
  mysql_free_result(result);
  return row[0];
}
char* database::getlandX(std::string username){
  connect();
  mysql_query(con, "USE users");
  std::stringstream ss;
  ss << "SELECT landx FROM users WHERE username=" << "'" << username << "'";
  std::string insert;
  insert = ss.str();
  const char *c = insert.c_str();
  mysql_query(con, c);
  MYSQL_RES *result;
  result = mysql_store_result(con);
  MYSQL_ROW row;
  row = mysql_fetch_row(result);
  if(row == NULL){
    std::cout << "ERROE ME BOI" << std::endl;
    return "ERROR";
  }
  mysql_close(con);
  mysql_free_result(result);
  return row[0];
}
void database::connect(){
  con = mysql_init(NULL);

  if(con == NULL){
    std::cout << mysql_error(con) << std::endl;
    exit(1);
  }

  if(mysql_real_connect(con, "127.0.0.1", "root", "password", "users", 3306, NULL, 0) == NULL){
    std::cout << mysql_error(con) << std::endl;
    exit(1);
  }
}

}
