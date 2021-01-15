//
//  SavingsAccount.cpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 11/1/21.
//

#include <iostream>
#include <string>
#include "SavingsAccount.hpp"
#include "Account.hpp"

SavingsAccount::SavingsAccount(std::string name)
: SavingsAccount(name, 100.00)
{
}

/**
 * this is calling the Account classes constructor and passes the name
 * since C++ supports multiple inheritance there's no super
 * you have to specify the name of the base class
 */
SavingsAccount::SavingsAccount(std::string name, double balance)
: Account(name, balance)
{
}

SavingsAccount::~SavingsAccount()
{
}

double SavingsAccount::getIntRate() const
{
  return this->INTEREST_RATE;
}

double SavingsAccount::expectedAnnualReturn() const
{
  return balance * INTEREST_RATE / 100;
}

bool SavingsAccount::deposit(double amount)
{
  amount += amount * (INTEREST_RATE / 100);
  return Account::deposit(amount);
}

bool SavingsAccount::withdraw(double amount)
{
  return Account::deposit(amount);
}

void SavingsAccount::print(std::ostream &out) const
{
  out << "Account Id: " << id << ",\n"
      << "Savings Account Name: " << name << ",\n"
      << "Account Balance: $" << balance << ",\n"
      << "Interest Rate: " << INTEREST_RATE << "%";
}
