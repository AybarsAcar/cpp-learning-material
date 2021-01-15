//
//  main.cpp
//  exception-handling
//
//  Created by Aybars Acar on 12/1/21.
//

#include <iostream>
#include "Account.hpp"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

double calcKmPerL(int km, double l);

class DivideByZeroException
{
  
};

class NegativeValueException
{
  
};


int main(int argc, const char * argv[])
{
  int km {};
  double liter {};
  double kmPerLiter{};
  
  cout << "Enter the km: ";
  cin >> km;
  cout << "Enter the liters: ";
  cin >> liter;
  
  try
  {
    kmPerLiter = calcKmPerL(km, liter);
    cout << "Km/l: " << kmPerLiter << endl;
  }
  catch (DivideByZeroException &ex)
  {
    cerr << "Cannot divide by 0" << endl;
  }
  catch (NegativeValueException &ex)
  {
    cerr << "Cannot accept negative values" << endl;
  }
  catch(...)  // catch all exception handler
  {
    cerr << "Unknown exception" << endl;
  }
  
  try
  {
    Account account ("Aybars", 100);
    account.withdraw(200);
  }
  catch(IllegalBalanceException &ex)
  {
    cerr << ex.what() << endl;
  }
  catch(InsufficientFundsException &ex)
  {
    cerr << ex.what() << endl;
  }
  
  
  return 0;
}

//double calcKmPerL(int km, double liter)
//{
//  if (liter == 0) throw 0;
//
//  if (km < 0 || liter < 0) throw string{"Illegal Arguement Exception"};
//
//  return static_cast<double>(km) / liter;
//}

/**
 * this throws our custom Exception classes
 */
double calcKmPerL(int km, double liter)
{
  if (liter == 0) throw DivideByZeroException();
  
  if (km < 0 || liter < 0) throw NegativeValueException();
  
  return static_cast<double>(km) / liter;
}
