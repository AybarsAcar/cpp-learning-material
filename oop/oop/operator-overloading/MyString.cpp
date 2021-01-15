//
//  MyString.cpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#include <cstring>
#include <iostream>
#include "MyString.hpp"

MyString::MyString()
: str{nullptr}
{
  str = new char[1];
  *str = '\0';
}

MyString::MyString(const char *s)
: str{nullptr}
{
  if (s == nullptr)
  {
    str = new char[1];
    *str = '\0';
  }
  else
  {
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
  }
}

MyString::MyString(const MyString &source)
: str{nullptr}
{
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
}

MyString::MyString(MyString &&source)
: str(source.str)
{
  source.str = nullptr;
}

MyString::~MyString()
{
  delete [] str;
}

void MyString::display() const
{
  std::cout << str << ": " << getLength() << std::endl;
}

int MyString::getLength() const
{
  return std::strlen(str);
}

const char *MyString::getStr() const
{
  return str;
}

/**
 * Assignment operator overloading for our MyString class
 */
MyString &MyString::operator=(const MyString &rhs)
{
//  check for self assignment - make sure do not assign to yourself
  if (this == &rhs) return *this;   // return current object
  
  
//  deallocate storage for this->str since we are overwriting it
//  so we wont end up with orphaned data thus memory leak
  delete [] str;
  
//  allocate storage on the heap then copy
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
  
  return *this;
}

/**
 * MOove assignment operator
 * used for r value assingment
 * which makes it super efficient since we dont do the overhead of copying
 */
MyString &MyString::operator=(  MyString &&rhs)
{
  if (this == &rhs) return *this;    // return if current object
  
  
//  deallocate storage for this->str since we are overwriting it
//  so we wont end up with orphaned data thus memory leak
  delete [] str;
  
//  assign right handside pointer to the left hand side's pointer
  str = rhs.str;
  
//  nullify the right handside pointer
  rhs.str = nullptr;
  
  return *this;
}

/**
 * compares the content of MyString class
 * returns true if the *char equals each other
 */
bool MyString::operator==(const MyString &rhs) const
{
  return (std::strcmp(str, rhs.str) == 0);
}

/**
 * compares the content of MyString class
 * returns true if the *char does not equal each other
 */
bool MyString::operator!=(const MyString &rhs) const
{
  return (std::strcmp(str, rhs.str) != 0);
}

/**
 * this makes hte string lowercase
 */
MyString MyString::operator-() const
{
//  copy of the current object
//  temporary area buff
  char *buff = new char[std::strlen(str) + 1];
  std::strcpy(buff, str);
  
//  make it lowercase
  for (size_t i {0}; i < std::strlen(buff); i++)
  {
    buff[i] = std::tolower(buff[i]);
  }
  
//  make the new object on the stack
  MyString temp {buff};
  
//  make sure to deallocate the space used by buf
//  to avoid memory leak
  delete [] buff;
  
  return temp;
}

/**
 * this overload concetenates 2 MyString objects
 */
MyString MyString::operator+(const MyString &rhs) const
{
//  allocate storage on the heap
  char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
  
//  copy the first string and concat the other one
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);
  
  MyString temp {buff};
  
  delete [] buff;
  
  return temp;
}

/**
 * overloaded insertion operator
 * prints the class
 */
std::ostream &operator<<(std::ostream &out, const MyString &rhs)
{
  out << rhs.str;
  return out;
}

/**
 * overloaded extraction operator
 * reads the used input
 */
std::istream &operator>>(std::istream &in, MyString &rhs)
{
//  create a buffer to store user input
//  make it large so we dont run out of buffer
  char *buff = new char[1000];
  
  in >> buff;
  
  rhs = MyString(buff);
  
  delete [] buff;
  
  return in;
}
