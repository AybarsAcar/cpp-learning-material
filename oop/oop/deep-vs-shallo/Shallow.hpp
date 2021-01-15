//
//  Shallow.hpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#ifndef Shallow_hpp
#define Shallow_hpp

#include <stdio.h>

/**
 * this class is to demonstrate the problems with the Shallow Copy
 * with Shallow copy when the object is deleted
 * the copied object may still point to the same reference assuming its still valid
 */
class Shallow
{
private:
  int *data;
  
public:
  Shallow(int d);
  Shallow(const Shallow &source);
  ~Shallow();
  
  void setData(int d);
  int getData();
};

#endif /* Shallow_hpp */
