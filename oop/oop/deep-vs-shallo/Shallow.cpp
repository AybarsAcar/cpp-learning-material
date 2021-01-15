//
//  Shallow.cpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#include "Shallow.hpp"
#include <iostream>

/**
 * Constructor
 */
Shallow::Shallow(int d)
{
  data = new int;
  *data = d;
}

/**
 * does shallow copy
 * we just copy to the pointer not what the pointer is pointing to
 */
Shallow::Shallow(const Shallow &source)
: data(source.data)
{
  std::cout << "Copy constructor - Shallow Copy" << std::endl;
}

Shallow::~Shallow()
{
  delete data;    // release the storage
  std::cout << "Destructor freeing data" << std::endl;
}

void Shallow::setData(int d)
{
  *data = d;
}

int Shallow::getData()
{
  return *data;
}
