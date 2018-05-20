#include "tui.h"
#include "database.h"

namespace ui{
tui::tui(){
}

int tui::menu(){
  users.init();
  std::cout << "--------------------\n::ASCII UNIVERSE::" <<  "\n1)login\n2)create account" << std::endl;
  std::cin >> input;
  if(process() == 1){
    return 1;
  }
  return 0;
}
int tui::process(){
  if (input == "1"){
    login();
  }
  if (input == "2"){
    create();
  }
  if (input == "q"){
    return 1;
  }
  return 0;
}
void tui::login(){
  std::string username;
  std::string password;
  std::string enteredpaswd;
  users.init();
  std::cout << "enter your username" << std::endl;
  std::cin >> username;
  password = users.getpaswd(username);
  if (password == "NOT VALID USERNAME"){
  }
  else{
  std::cout << "enter your password" << std::endl;
  std::cin >> enteredpaswd;
  if(enteredpaswd == password){
    std::cout << "correct password" << std::endl;
    std::cout << username << std::endl;
    accountmenu(username);
  }
  else{
    std::cout << "incorrect password" << std::endl;
  }
  }
}
void tui::create(){
  std::string password;
  std::string username;
  std::cout << "enter you username" << std::endl;
  std::cin >> username;
  if(usercheck(username) == true){
  std::cout << "enter you password" << std::endl;
  std::cin >> password;
  if(paswdcheck(password) == true){
  users.init();
  users.adduser(password, username, "land not yet modified");
}
else{
  std::cout << "invalid password" << std::endl;
}
}
}
bool tui::paswdcheck(std::string str){
  if(str.length() <= 10 && str.length() >= 5){
    return true;
  }
  else{
    return false;
  }
}
bool tui::usercheck(std::string str){
  if(users.does_exist_user(str) == true){
    std::cout << "that username allready exists" << std::endl;
    return false;
  }
  if(str.length() <= 7){
    std::cout << "valid username" << std::endl;
    return true;
  }
  else{
    std::cout << "usernames must be 7 characters or less" << std::endl;
    return false;
  }
}
void tui::accountmenu(std::string username){
ac::account acnt(username);
acnt.menu();
}
}
