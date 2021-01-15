//
//  main.cpp
//  oop
//
//  Created by Aybars Acar on 7/1/21.
//

#include <iostream>
#include <vector>

#include "Account.h"
#include "Player.hpp"
#include "Shallow.hpp"
#include "Deep.hpp"
#include "Move.hpp"
#include "MyString.hpp"

using namespace std;

void displayShallow(Shallow s);
void displayDeep(Deep s);
void displayAccount(const Account &account);
void displayActiveAccounts();

int main(int argc, const char * argv[])
{
  displayActiveAccounts();
  
  Player player1 ("Aybars");
  Player player2 {"Shuang"};
  
  Player players[] {player1, player2};

  
  Player *enemy {nullptr};
  enemy = new Player ("Darth Vader");
  
  enemy -> name = "Darth Vader";
  
  delete enemy;   // destructor is called
  
  cout << player2.name << endl;
  
  player1.talk("hello");
  
  Account account1("Aybars's Account");
  
  cout << "My Balance is: " << account1.getBalance() << endl;
  
  cout << "Player 1 health: " << player1.health << endl;
  
  displayActiveAccounts();
  
 /*
  This Shallow Copy crashes the code because its trying to delete a nullptr
  
  Shallow obj1 {100};
  displayShallow(obj1);
  
  Shallow obj2 {obj1};  // copy
  obj2.setData(1000);
  displayShallow(obj2);
  */
  
  Deep obj1 {100};
  displayDeep(obj1);
  
  Deep obj2 {obj1};  // copy
  obj2.setData(1000);
  displayDeep(obj2);
  displayDeep(obj1);
  
  vector<Move> myVector;
  
//  push the Move objects as r-values
//  when we have a move constructor it will be called instead of being copied
  myVector.push_back(Move{20});
  myVector.push_back(Move{30});
  
  
//  const Account object but we can call the methods that
//  dont violate the const correctness invariance
  const Account anAccount {"Constant account"};
  displayAccount(anAccount);
 
  displayActiveAccounts();
  
  Account *account = new Account("Pointer one", 120);
  
  displayActiveAccounts();
  
  delete account;   // delete the pointer
  
  displayActiveAccounts();
 
  
//  use MyString
  MyString empty;
  MyString aybars {"Aybars"};
  MyString copyMe {aybars};

  empty = aybars;
  empty.display();
  
  empty = "I am changing it";   // uses move operator
  empty.display();
  
  MyString concatted = aybars + " acar";
  concatted.display();
  
  cout << concatted << endl;
  
//  test reading
  MyString readFromUserInput;
  cout << "What is your name? ";
  cin >> readFromUserInput;
  
  cout << "Read from user input: " << readFromUserInput << endl;
  
  return 0;
}


void displayShallow(Shallow s)
{
  cout << s.getData() << endl;
}


void displayDeep(Deep s)
{
  cout << "The value stored in the object: " << s.getData() << endl;
}

void displayAccount(const Account &account)
{
  cout << "The name of the account: " << account.getName() << endl;
  cout << "The balance of the account: " << account.getBalance() << endl;
}

void displayActiveAccounts()
{
  cout << "-------------------" << endl;
  cout << "Number of accounts " << Account::getNumAccounts() << endl;
  cout << "-------------------" << endl;
}
