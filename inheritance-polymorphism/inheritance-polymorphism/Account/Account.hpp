//
//  Account.hpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 11/1/21.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>
#include "IPrintable.hpp"

/**
 * Base classes for the accounts
 */
class Account : public IPrintable
{
private:
  
  
protected:
  static int ID;
  int id;
  std::string name;
  double balance;
  
public:
  Account(std::string name, double balance);
  Account(std::string name);
  virtual ~Account() = default;
  
  virtual bool deposit(double amount);
  virtual bool withdraw(double amount);
  std::string getName() const;
  double getBalance() const;
  
  virtual void print(std::ostream &out) const override;
};

#endif /* Account_hpp */
