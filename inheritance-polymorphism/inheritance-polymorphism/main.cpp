//
//  main.cpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 11/1/21.
//

#include <iostream>
#include "SavingsAccount.hpp"
#include "Account.hpp"
#include <vector>
#include <memory>

using namespace std;

void depositToAccount(Account &account, double amount);

int main(int argc, const char * argv[])
{
  SavingsAccount *savingsAccount = new SavingsAccount("Aybars Savings Account");
  savingsAccount->deposit(15.00);
  double intRate = savingsAccount->getIntRate();
  
  cout << intRate << endl;
  cout << savingsAccount->getName() << endl;
  
  Account myAccount{"Aybars Regular Account", 120.00};
  
  cout << myAccount.getName() << endl;
  
  cout << myAccount << endl;
  cout << *savingsAccount << endl;
  
  cout << "Expected Return: $" << savingsAccount->expectedAnnualReturn() << endl;
  
  Account *anotherAccount = new Account("Another account", 80);
  SavingsAccount *someSavingsAccount = new SavingsAccount("Savings account", 20);
  
  
//  initialising a unique_ptr
  auto p2 = make_unique<SavingsAccount>("unique_ptr Account");
//  another way
  unique_ptr<Account> p3 {new Account {"Another unique_ptr Account", 300.00}};

  
//  we can push in any Account object to our vector
//  it has to be reference or a pointer
//  Account *array[] = {savingsAccount, &myAccount};      // or in an array as well
  vector<Account*> accounts {savingsAccount, &myAccount, anotherAccount, someSavingsAccount};
  
//  we have to use move semantics for unique_ptr because they cant be copied or reassigned
//  first create a vector for the account unique pointers
//  because we cannot push it to raw pointer vectors
  vector<unique_ptr<Account>> accountsUP;
  accountsUP.push_back(move(p2));
  accountsUP.push_back(move(p3));
  
  for (const auto &account : accountsUP)
  {
    cout << "-----------------------" << endl;
    depositToAccount(*account, 2.00);
    cout << *account << endl;
  }
  
  
  for (auto acc_ptr : accounts)
  {
//    acc_ptr->deposit(2.00);
    cout << "-----------------------" << endl;
    depositToAccount(*acc_ptr, 2.00);
    cout << *acc_ptr << endl;
  }
  cout << "-----------------------" << endl;
  
  delete savingsAccount;
  delete anotherAccount;
  delete someSavingsAccount;

}

/**
 * use reference in the method
 * so we can dynamically bind the appropriate overridden method
 */
void depositToAccount(Account &account, double amount)
{
  account.deposit(amount);
}
