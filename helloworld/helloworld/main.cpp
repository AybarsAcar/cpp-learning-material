//
//  main.cpp
//  helloworld
//
//  Created by Aybars Acar on 5/1/21.
//

#include <iostream>

using namespace std;

/**
 * the main function the compiler looks for
 */
int main()
{
  int firstNumber;
  int secondNumber;

  cout << "Enter the first number: ";
  cin >> firstNumber;

  cout << "Enter the second number: ";
  cin >> secondNumber;

  cout << "Amazing so your favourite number is " << firstNumber + secondNumber << endl; // endl -> "\n"

  return 0;
}
