//
//  Account.h
//  oop
//
//  Created by Aybars Acar on 7/1/21.
//

#include <string>

#ifndef Account_h
#define Account_h

/**
 * Accounts class
 */
class Account
{
private:
  std::string name;
  double balance;
  static int numAccounts;
  
public:
  
  /**
   * Delegating a constructor
   * this is like this(name, 100.0)) in Java
   */
  Account(std::string name)
  : Account {name, 100.00}
  {
  }
  
  Account(std::string name, double balance)
  : name {name}, balance {balance}
  {
    numAccounts++;
  }
  
  static int getNumAccounts();
  
  double getBalance() const;        // const keyword allows us the call methods on const object instantiations
  
  std::string getName() const;
  
  void setName();
  
  bool deposit(double balance);
  
  bool withdrawl(double);
  
  /**
   * Copy Constructor
   * called when the object is copied
   */
  Account(const Account &source)
  : name{source.name}, balance{source.balance}
  {
  }
  
  ~Account()
  {
    numAccounts--;
  }
};


#endif /* Account_h */
