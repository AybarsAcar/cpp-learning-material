//
//  Account.hpp
//  exception-handling
//
//  Created by Aybars Acar on 12/1/21.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>

class Account
{
private:
  std::string name;
  double balance;
  
public:
  Account(std::string name, double balance);
  ~Account() = default;
  
  double getBalance();
  void withdraw(double amount);
};

#endif /* Account_hpp */
