//
//  stream-manipulators.cpp
//  streams-io
//
//  Created by Aybars Acar on 13/1/21.
//

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/**
 * showcases the stream manipulators and how they affect std::cout
 */
void runManipulators()
{
//  Boolean Manipulators //
  /*cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;
  
  cout << boolalpha;  // set the boolalpha for further streams
  cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;
  
  cout << noboolalpha;  // toggle back to noboolalpha
  cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;
  
  cout.setf(std::ios::boolalpha);  // setting by method
  cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;
  
  cout << resetiosflags(std::ios::boolalpha);  // reset to the original one
  cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;*/
  
//  Integer Manipulators //
  /*int num {255};
  
  cout << showbase << uppercase;
  cout << dec << num << endl;
  cout << hex << num << endl;
  cout << oct << num << endl;
  
  cout << showpos << dec;
  cout << 233 << endl;
  cout << -233 << endl;*/
  
//  Floating Point Number Manipulators //
  /*double n {1312221.2};
  cout << n << endl;
  
  cout << setprecision(12);
  cout << n << endl;
  
  cout << setprecision(2) << fixed << showpoint;
  cout << n << endl;*/
  
//  Stream Formatters //
  int num1 {1234};
  double num2 {1234.5678};
  string hello {"Hello"};
  
  cout << num1 << num2 << hello << endl;
  
  cout << setw(10) << num1 << setw(15) << num2 << setw(8) << hello << endl;
  cout << setfill('-') << setw(10) << num1 << setw(15) << num2 << hello << endl;
  
  cout << setfill('-') << setw(10) << num1 << setw(15) << num2 << setfill('*') << setw(8) << hello << endl;
}
