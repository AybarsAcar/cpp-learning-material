//
//  Account.cpp
//  exception-handling
//
//  Created by Aybars Acar on 12/1/21.
//

#include "Account.hpp"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

Account::Account(std::string name, double balance)
: name(name), balance(balance)
{
  if (balance < 0) {
    throw IllegalBalanceException();
  }
}

double Account::getBalance()
{
  return this->balance;
}

void Account::withdraw(double amount)
{
  if (balance - amount < 0) throw InsufficientFundsException();
  
  balance -= amount;
}
