//
//  main.cpp
//  stringsandmore
//
//  Created by Aybars Acar on 6/1/21.
//

#include <iostream>
#include <cstring>            // for c-style string functions
#include <cctype>             // for character based functions

using namespace std;

/**
 * main function the compiler looks for
 */
int main()
{
//  C-style strings
//  Make sure to terminate with 0
  char firstName[] {'A', 'y', 'b', 'a', 'r', 's', 0};
  cout << firstName << " has length of " << strlen(firstName) << endl;
  
  char lastName[20];
  
  cout << "What is you last name? ";
  cin >> lastName;
  
  cout << lastName << " has length of " << strlen(lastName) << endl;
  
  
  char fullName[20];
  strcpy(fullName, firstName);
  strcat(fullName, " ");
  strcat(fullName, lastName);
  
  cout << fullName << endl;
  
  
//  C++ style string
  string myString = "hello";
  
  string sentence = myString + "World";
  
  cout << sentence << endl;
  
  cout << myString.substr(0, 2) << endl;
  
  string s1 {"Apple"};
  string s2 (s1, 0, 3);

  cout << s2 << endl;
  
  cout << s1.at(3) << endl;
  
//  assignment or access
//  s1.at(0) = 'J';
//  cout << s1 << endl;
//
//  s1[0] = 'P';
//  cout << s1 << endl;
  
  for (int i = 0; i < s1.length(); i++)
  {
    cout << "Character at location " << i << " is " << s1.at(i) << endl;
  }
  
  string yourName;
  cout << "Please enter your name here and end it with X" << endl;
  getline(cin, yourName, 'X');

  cout << yourName << endl;
  
  return 0;
}
