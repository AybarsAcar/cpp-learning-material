//
//  vectorProj.cpp
//  stl-proj
//
//  Created by Aybars Acar on 14/1/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "Item.h"

template<typename T>
void displayVector(std::vector<T> &v)
{
  std::cout << "[ ";
  for (auto elem : v)
  {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void vectorProjExe()
{
  std::vector<int> myVector {1, 2, 3, 4};
  
  /*
   NO BOUNDS CHECKING - INSERTS INTO THE BACKING PRIMITIVE ARRAY
   myVector[10] = 20;
   std::cout << myVector[10] << std::endl;
  */
  
  std::cout << myVector.max_size() << std::endl;
  std::cout << myVector.capacity() << std::endl;
  std::cout << myVector.size() << std::endl;
  
  std::vector<int> v1 (10, 100);
  
  displayVector(v1);
  std::cout << "Capacity: " << v1.capacity() << std::endl;
  
  v1.push_back(20);
  displayVector(v1);
  
//  erase if its greater than 20
  auto it = v1.begin();
  while (it != v1.end())
  {
    if (*it > 20)
    {
      v1.erase(it);
    }
    else it++;
  }
  displayVector(v1);
  
  std::copy(myVector.begin(), myVector.end(), std::back_inserter(v1));
  displayVector(myVector);
  displayVector(v1);
  
  v1.clear();
  displayVector(v1);
}
