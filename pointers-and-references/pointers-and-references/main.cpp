//
//  main.cpp
//  pointers-and-references
//
//  Created by Aybars Acar on 7/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

void doubleData(int *pointer);
void swap(int &a, int&b);
void displayVector(const vector<string> *const vector);
void display(const int *array, int sentinel);
int *createArray(size_t size, int initValue = 0);
void display(const int *array, size_t size);
int *getNewArray(int *arr1, size_t s1, int *arr2, size_t s2);

int main(int argc, const char * argv[])
{
  int a {0};
  
  cout << a << endl;                              // prints out the value
  cout << &a << endl;                             // prints out the memory address
  cout << sizeof(a) << endl;                      // prints the size of the pointer
  
  cout << "\n-------------------------------" << endl;
  
  int num {20};
  
  cout << "Value of num: " << num << endl;
  cout << "Size of num (int in my machine): " << sizeof(num) << endl;
  cout << "Memory address of num: " << &num << endl;

  cout << "\n-------------------------------" << endl;
  
  int *p;
  cout << "Value of p: " << p << endl;            // garbage because not initialised
  cout << "Address of p: " << &p << endl;
  cout << "Size of p:" << sizeof(p) << endl;      // size of a pointer
  
  p = nullptr;
  cout << "\nValue of p is" << p << endl;
  
  cout << "\n-------------------------------" << endl;
  
  int *p1 {nullptr};
  double *p2 {nullptr};
  unsigned long long *p3 {nullptr};
  vector<string> *p4 {nullptr};
  string *p5 {nullptr};
  
//  They should print the same size in bytes -- all 8 bytes
  cout << "sizeof p1 is: " << sizeof(p1) << endl;
  cout << "sizeof p2 is: " << sizeof(p2) << endl;
  cout << "sizeof p3 is: " << sizeof(p3) << endl;
  cout << "sizeof p4 is: " << sizeof(p4) << endl;
  cout << "sizeof p5 is: " << sizeof(p5) << endl;
  
  cout << "\n-------------------------------" << endl;

  int score {10};
  
  int *scorePointer {nullptr};
  
  scorePointer = &score;                        // point the pointer to the score's memory address
  
  cout << "Value of score: " << score << endl;
  cout << "Memory address of score: " << &score << endl;
  cout << "Value of scorePointer: " << scorePointer << endl;
  
//  dereferencing
  cout << "scorePointer points to the following value: " << *scorePointer << endl;
  
  cout << "\n-------------------------------" << endl;
  
  string name {"Aybars"};                     // initialise a string
  string *namePointer {&name};                // initialise a pointer for my name
  
  if (namePointer == &name)
    cout << "namePointer points to the memory address of name" << endl;
  
  if (*namePointer == name)
    cout << "Dereferencing namePointer equals name" << endl;
  
  cout << "\n-------------------------------" << endl;
  
//  Dynamically Reallocate memory
  int *intPointer = nullptr;
  
  intPointer = new int;               // assign a memory address to the pointer
  *intPointer = 10;                   // store the value at that memory address
  
  cout << *intPointer << " is stored at the memory location: " << intPointer << endl;
  
  delete intPointer;                  // free up the memory
  
  cout << "\n-------------------------------" << endl;
  
  size_t size{0};
  double *tempPointer {nullptr};
  
  cout << "How many temp? ";
  cin >> size;
  
  tempPointer = new double[size];      // allocate that chunk of memory for hte array
  
  cout << "The address of the array[0] is at " << tempPointer << endl;
  
  delete [] tempPointer;               // free up the memory
  
  cout << "\n-------------------------------" << endl;
  
  int scores[] {100, 30, 29, -1};
  
  int *scoresPointer {scores};
  
  cout << scores << " == " << scorePointer << endl;
  
  cout << *scores << " == " << scores[0] << endl;
  cout << *(scoresPointer + 1) << " == " << scores[1] << endl; // doesn't add 1 adds 4 bytes so next address
  cout << scoresPointer[0] << " == " << scores[0] << endl;
  cout << *(scores + 2) << " == " << scores[2] << endl;
  
  cout << "\n-------------------------------" << endl;
  
  int scoresLength = sizeof(scores) / sizeof(*scores);
  
  cout << scoresLength << " is the lenght of scores array" << endl;
  
  while (*scoresPointer != -1)
  {
    cout << *scoresPointer++ << endl;   // will print each array element up to -1 which is the sentinal value
  }
  
  cout << "\n-------------------------------" << endl;
  
  string s1 {"Aybars"};
  string s2 {"Aybars"};
  
  string *sp1 = &s1;
  string *sp2 = &s2;
  string *sp3 = &s1;
  
//  They are equal if they point to the same object
  sp1 == sp2 ? cout << "They are equal" : cout << "No they are not" << endl;
  sp1 == sp3 ? cout << "They are equal" : cout << "No they are not" << endl;
  
  cout << "\n-------------------------------" << endl;
  
  doubleData(&scores[1]); // expect 60
  cout << scores[1] << endl;
  
  int myInteger = 80;
  doubleData(&myInteger); // expect 160
  cout << myInteger << endl;
  
  int *myPointer = &myInteger;
  doubleData(myPointer); // expect 320
  cout << myInteger << endl;
  
  cout << "\n-------------------------------" << endl;
  
  int myOtherInteger = 20;
  
  swap(myInteger, myOtherInteger);
  cout << "myInteger: " << myInteger << endl;
  cout << "myOtherInteger: " << myOtherInteger << endl;
  
  cout << "\n-------------------------------" << endl;
  
  vector<string> myVector {"Aybars", "Shuang", "Isil", "Zuhre"};
  displayVector(&myVector);
  
  
  display(scores, -1);
  
  cout << "\n-------------------------------" << endl;

  int *myArray;
  size_t sizeOfMyArray = 10;
  myArray = createArray(sizeOfMyArray, 20);
  display(myArray, sizeOfMyArray);
  
  delete [] myArray;
  
  cout << "\n-------------------------------" << endl;
  
  int myNum {10};
  int &ref {myNum};   // setting an alias to the myNum
  
  cout << ref << endl;
  
  cout << "\n-------------------------------" << endl;
  
  vector<int> myIntegerVector {2, 39, 10, 30, 20, 10, 20, 39};
  
//  to update the elements of our vector we need to pass in the actual vector not a copy to the enhanced loop
  for (auto &elem : myIntegerVector)
  {
    elem = 0;
  }
  
  for (auto elem : myIntegerVector)
  {
    cout << elem << " ";
  }
  
  cout << "\n-------------------------------" << endl;
  
  int arr1[] {10, 20, 30};
  int arr2[] {2, 3, 4, 5};
  size_t arr1Size = sizeof(arr1) / sizeof(*arr1);
  size_t arr2Size = sizeof(arr2) / sizeof(*arr2);
  cout << arr1Size << " " << arr2Size << endl;
  
  int *resultArray { getNewArray(arr1, arr1Size, arr2, arr2Size) };
  
  for (int i{0}; i < 12; i++)
  {
    cout << resultArray[i] << endl;
  }
  
  
  cout << endl;
  return 0;
}


/**
 * doubles whatever data it is pointing to
 */
void doubleData(int *pointer)
{
  *pointer *= 2;
}

void swap(int &a, int&b)
{
  int temp = a;
  a = b;
  b = temp;
}

void displayVector(const vector<string> *const vector)
{
  for (auto elem : *vector) {
    cout << elem << endl;
  }
}

void display(const int *array, int sentinel)
{
  while (*array != sentinel) {
    cout << *array++ << endl;
  }
}

int *createArray(size_t size, int initValue)
{
  int *newStorage {nullptr};
  
  newStorage = new int[size];
  for (size_t i {0}; i < size; i++)
  {
    *(newStorage + i) = initValue;
  }
  return newStorage;
}

void display(const int *array, size_t size)
{
  for (size_t i{0}; i < size; i++)
  {
    cout << array[i] << endl;
  }
}

/**
 * Challange
 * takes 2 arrays and their sizes size1 and size2
 * we will allocate an array dynamically with size size1*size2
 * take each element in array 2 and multiply with the elements in array 1
 */
int *getNewArray(int *arr1, size_t s1, int *arr2, size_t s2)
{
  int *result = new int[s1 * s2];
  
  int position{0};
  for (int j{0}; j < s2; j++)
  {
    for (int i{0}; i < s1; i++)
    {
      result[position++] = arr1[i] * arr2[j];
    }
  }
  return result;
}
