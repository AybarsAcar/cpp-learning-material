//
//  main.cpp
//  variablesandconstants
//
//  Created by Aybars Acar on 5/1/21.
//

#include <iostream>
#include <climits>
#include <vector>

// dont use this
// it is a legacy way to declare a constant -- macro
#define MY_CONSTANT = 100

using namespace std;

// global var declaration
string myName {"Aybars"};

/**
 * main method the compiler looks for with the system arguements
 */
int main(int argc, const char * argv[])
{
  //Declared constant
  const string myLastName {"Acar"};
  
  int age;             // uninitialised
  int age2 = 21;       // C-like initialisation
  int age3 (21);       // Constructor initialisation
  int age4 {21};       // C++ list initialisatoin syntax
  
  char myInitial = 'A';
  
  long double largeValue {2.7e120};
  
//  declaring an integer array
  int myArray [5] {20, 103, 120, 39, 20};
  
  age = 30;
  
  cout << age << age2 << age3 << age4 << endl;
  
  cout << "My name is " << myName << endl;
  cout << "My intial is " << myInitial << endl;
  
  cout << largeValue + age << endl;
  
  cout << sizeof(int) << endl;
  
  cout << "Maximum int: " << INT_MAX << endl;
  cout << "Minimum int: " << INT_MIN << endl;
  cout << "Size of my name: " << sizeof(myName) << endl;
  
//  get the size of the array
  const int N = sizeof(myArray) / sizeof(*myArray);
  for (int i = 0; i < N; i++) {
    cout << "variable at[" << i << "] -> " << myArray[i] << endl;
  }
  
  cout << "Memory address of my array is " << myArray << endl;
  
//  Vector
  vector<int> myVector {10, 20, 30};
  
  myVector.push_back(20);
  
  cout << myVector.at(0) << endl;
  cout << myVector[0] << endl;
  
  cout << "Popped Elements: " << myVector.size() << endl;
  
//  2D vector
  vector<vector<int>> my2DVector
  {
    {1, 2, 3},
    {1, 20, 30},
    {1, 2, 3},
  };
  
  cout << my2DVector.at(1).at(2) << endl; // returns 30;
  
//  you dont need to explicitly cast to an integer
  int result = 10.0 / 6;
  
  cout << "This is the result: " << result << endl;
  
  cout << "Prints the ASCII  value of char 'a': " << static_cast<int>('a') << endl;
  
//  c-style casting
  cout << "Prints the ASCII  value of char 'A': " << (int) 'A' << endl;

  
  string s1 = "this is a string";
  string s2 = "this is a string";
  
  int comparison = s1.compare(s2);
  
  if (comparison == 0)
  {
    cout << "2 strings are equal" << endl;
  }
  
  if (s1 == s2)
  {
    cout << "2 strings are the same object" << endl;
  }
  
  char firstChar = s1.at(0);
  cout << "the fist character: " << firstChar << endl;
  
//  Boolean
  bool thisIsFalse = false;
  
  cout << "the value is: " << boolalpha << thisIsFalse << endl;
  
  bool isEqual = 10 == 10.0;
  cout << "10 == 10.0 returns " << boolalpha << isEqual << endl;
  
  
// ********************************  CONTROL FLOW ******************************** //
  
//  same as java
  int value;
  
  cout << "please enter a number: ";
  cin >> value;
  
  if (value < 10)
  {
    cout << "the value you entered is less than 10" << endl;
  }
  else if (value >= 10 && value < 50)
  {
    cout << "the value you entered is between 10 and 50" << endl;
  }
  else
  {
    cout << "the value you entered is greater than or equal 50" << endl;
  }
  
  switch (value) {
    case 20:
    case 40:
      cout << "woohoo you entered 20 or 40" << endl;
      break;
      
    case 30:
      cout << "woohoo you entered 30" << endl;
      break;
      
    case 50:
      cout << "woohoo you entered 50" << endl;
      break;
      
    default:
      cout << "wow you entered a very large nubmer" << endl;
      break;
  }
  
//  creating an enum
  enum Direction
  {
    NORTH,
    SOUTH,
    WEST,
    EAST,
  };
  
//  enhanced loop
  for (int elem : myArray) {
    cout << elem << endl;
  }
  
//  we can use auto which is similar to var in C#
  for (auto elem : myArray) {
    cout << "Each element: " << elem << endl;
  }
  
  
//  Simple stupid program for my array
  bool isRunning {};
  char start;
  
  cout << "Do you want to play?" << endl;
  cin >> start;
  
  if (start == 'y' || start == 'Y') {
    isRunning = true;
  }
  
  while (isRunning) {
    char choice;
    cout << "What do you want to see? " << endl;
    cin >> choice;
    
    if (choice == 'P') {
      for (auto elem : myArray) {
        cout << "Each element: " << elem << endl;
      }
    }
    
    if (choice == 'T') {
      int total {0};
      for (auto elem : myArray) {
        total += elem;
      }
      cout << "Total is " << total << endl;
    }
    
    if (choice == 'A') {
      int total {0};
      for (auto elem : myArray) {
        total += elem;
      }
      cout << "Average is " << (double) total / N << endl;
    }
    
    if (choice == 'Q') {
      cout << "Thanks for playing" << endl;
      break;
    }
  }
  
  
  return 0;
}
