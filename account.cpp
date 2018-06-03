#include "account.h"

namespace ac{

account::account(std::string username):m_username(username){

}
void account::menu(){
  while(true){
  std::cout << "USER: "<< m_username << "\n" << "+----------------+" << std::endl;
  std::cin >> m_comd;
  if(process() == 1){
    break;
  }
}
}
int account::process(){
  if(m_comd == "update"){
    std::string land;
    std::cin >> land;
    users.edit_land(m_username, land);
    return 0;
  }
  if(m_comd == "show"){
    std::cout << users.getland(m_username) << std::endl;
    return 0;
  }
  if(m_comd == "b"){
    return 1;
  }

}
}