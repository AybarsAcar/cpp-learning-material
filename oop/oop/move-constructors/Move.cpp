//
//  Move.cpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#include <iostream>
#include "Move.hpp"

/**
 * Constructor
 */
Move::Move(int d)
{
  data = new int;
  *data = d;
}

/**
 * does deep copy
 * allocates memory to a new data which has the same value stored
 */
Move::Move(const Move &source)
: Move {*source.data}
{
  std::cout << "Copy constructor - Deep Copy" << std::endl;
}

/**
 * Move constructor
 * called when our object is an r-value
 */
Move::Move(Move &&source) noexcept
: data {source.data}
{
  source.data = nullptr;    // make sure to set it to a nullptr in move constructor to avoid memory leak
  std::cout << "Move constructor - moving resource: " << *data << std::endl;
}

Move::~Move()
{
  if (data != nullptr)
  {
    std::cout << "Destructor freeing data for: " << *data << std::endl;
  }
  else
  {
    std::cout << "Destructor freeing data" << std::endl;
  }
  
  delete data;    // release the storage
  
}

void Move::setData(int d)
{
  *data = d;
}

int Move::getData()
{
  return *data;
}
