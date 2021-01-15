//
//  MyString.hpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>

/**
 * Models a String backed by a char array
 * C style string
 * used to learn operator overloading
 */
class MyString
{
  friend std::ostream &operator<<(std::ostream &out, const MyString &rhs);
  friend std::istream &operator>>(std::istream &in, MyString &rhs);
  
private:
  char *str;
  
public:
  MyString();                                           // constructor
  MyString(const char *s);                              // constructor
  MyString(const MyString &source);                     // copy constructor
  MyString(MyString &&source);                          // move constructor
  ~MyString();                                          // destructor
  
  void display() const;
  int getLength() const;
  const char *getStr() const;
  
  MyString &operator= (const MyString &rhs);            // copy assignment (not constructions)
  MyString &operator= (MyString &&rhs);                 // move assignment
  
  bool operator== (const MyString &rhs) const;          // equality operator
  bool operator!= (const MyString &rhs) const;          // equality operator
  
  MyString operator- () const;                          // negate operator - makes it lowercase for our class
  MyString operator+ (const MyString &rhs) const;       // add operator - used for concatenation
};

#endif /* MyString_hpp */
