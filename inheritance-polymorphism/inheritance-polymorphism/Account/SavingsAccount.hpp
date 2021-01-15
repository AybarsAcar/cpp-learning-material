//
//  SavingsAccount.hpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 11/1/21.
//

#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

#include <stdio.h>
#include <string>
#include "Account.hpp"

class SavingsAccount : public Account
{
private:
  static constexpr double INTEREST_RATE = 3.0;
  
public:
  SavingsAccount(std::string name);
  SavingsAccount(std::string name, double balance);
  virtual ~SavingsAccount();
  
  virtual bool deposit(double amount) override;    // override the deposit from the parent
  virtual bool withdraw(double amount) override;
    
  double getIntRate() const;
  double expectedAnnualReturn() const;
  
  virtual void print(std::ostream &out) const override;
};


#endif /* SavingsAccount_hpp */
