//
//  Account.cpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 11/1/21.
//

#include <iostream>
#include <string>
#include "Account.hpp"

int Account::ID = 0;

Account::Account(std::string name, double balance)
: name{name}, balance{balance}, id{++ID}
{
}

Account::Account(std::string name)
: Account::Account(name, 100.00)
{
}

bool Account::deposit(double amount)
{
  if (amount < 0) return false;
  
  balance += amount;
  return true;
}

bool Account::withdraw(double amount)
{
  if (balance - amount > 0)
  {
    balance -= amount;
    return true;
  }
  else
  {
    return false;
  }
}

std::string Account::getName() const
{
  return this->name;
}

double Account::getBalance() const
{
  return this->balance;
}

void Account::print(std::ostream &out) const
{
  out << "Account Id: " << id << ",\n"
      << "Account Name: " << name << ",\n"
      << "Account Balance: $" << balance;
}
