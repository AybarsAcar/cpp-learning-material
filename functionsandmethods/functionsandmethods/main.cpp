//
//  main.cpp
//  functionsandmethods
//
//  Created by Aybars Acar on 6/1/21.
//

#include <iostream>
#include <cmath>                // math functions library
//#include <random>               // for statistical calculations
#include <vector>
#include <string>

using namespace std;

// function prototype
void greetingService(string);
double areaOfCircle(double);
string vectorToString(const vector<int> &input);  // const vector reference because we dont want to change it by mistake
double calculateCost(double baseCost, double taxRate = 0.08, double shipping = 5.00); // provide the default values
void printArray(const int[], size_t); // const int[] so we cannot change the array
void swap(int &a, int &b);

int main()
{
//  int myValue = sqrt(16);
//  cout << myValue << endl;
//  int randomValue = rand() % 100 + 1;    // random number between 100 and 1
  
  vector<int> randomValues {};
  
  for (int i = 0; i < 10; i++)
  {
    int randomNumber = rand() % 100 + 1;
    randomValues.push_back(randomNumber);
  }
  
  for (auto value : randomValues)
  {
    cout << value << endl;
  }
  
  greetingService("Aybars");
  
  double radius;
  cout << "what is the radius of your circle? ";
  cin >> radius;
  cout << "The area of your circle is " << areaOfCircle(radius) << endl;
  
  vector<int> myVector {10, 20, 10, 103, 103, 1202};
  cout << vectorToString(myVector) << endl;
  
  cout << calculateCost(100) << endl;
  
  int myArray[] {10, 20, 30, 40, 50};
  printArray(myArray, 5);
  
  int a = 5;
  int b = 10;
  
  swap(a, b);
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  return 0;
}


void greetingService(string name)
{
  cout << "Hello " << name << "!" << endl;
}

double areaOfCircle(double radius)
{
  return radius * radius * M_PI;
}

string vectorToString(const vector<int> &input)
{
  string result = "[";
  for (int i = 0; i < input.size() - 1; i ++) {
    result.append(to_string(input[i]));
    result.append(", ");
  }
  result.append(to_string(input[input.size() - 1]));
  result.append("]");
  
  return result;
}

double calculateCost(double baseCost, double taxRate, double shipping)
{
  return baseCost += (baseCost * taxRate) + shipping;
}

void printArray(const int arr[], size_t size)
{
  for (int i = 0; i < size; i++)
  {
    cout << to_string(arr[i]) << endl;
  }
}

/**
 * swaps the 2 integers
 * we need to make sure we pass in by reference
 */
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
