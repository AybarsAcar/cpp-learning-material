//
//  Account.cpp
//  oop
//
//  Created by Aybars Acar on 7/1/21.
//

#include <stdio.h>
#include "Account.h"
#include <string>

using namespace std;

int Account::numAccounts {0};           // initialise the static variable

int Account::getNumAccounts()
{
  return numAccounts;
}

double Account::getBalance() const
{
  return balance;
}

string Account::getName() const
{
  return name;
}

bool Account::deposit(double amount)
{
  balance += amount;
  return true;
}

bool Account::withdrawl(double amount)
{
  if (this -> balance - amount > 0)
  {
    this -> balance -= amount;
    return true;
  }
  return false;
}

