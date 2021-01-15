//
//  Deep.cpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#include <iostream>
#include "Deep.hpp"

/**
 * Constructor
 */
Deep::Deep(int d)
{
  data = new int;
  *data = d;
}

/**
 * does deep copy
 * allocates memory to a new data which has the same value stored
 */
Deep::Deep(const Deep &source)
: Deep {*source.data}
{
  std::cout << "Copy constructor - Deep Copy" << std::endl;
}

Deep::~Deep()
{
  delete data;    // release the storage
  std::cout << "Destructor freeing data" << std::endl;
}

void Deep::setData(int d)
{
  *data = d;
}

int Deep::getData()
{
  return *data;
}

