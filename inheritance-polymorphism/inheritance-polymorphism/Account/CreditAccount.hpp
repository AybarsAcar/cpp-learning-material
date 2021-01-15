//
//  CreditAccount.hpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 12/1/21.
//

#ifndef CreditAccount_hpp
#define CreditAccount_hpp

#include <stdio.h>

class CreditAccount : public Account
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

#endif /* CreditAccount_hpp */
