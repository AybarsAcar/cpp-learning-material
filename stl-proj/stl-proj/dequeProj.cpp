//
//  dequeProj.cpp
//  stl-proj
//
//  Created by Aybars Acar on 14/1/21.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <array>
#include <deque>

#include "Item.h"

template <typename T>
void displayDeque(std::deque<T> &d)
{
  for (int i{0}; i < d.size() - 1; i++)
  {
    std::cout << d.at(i) << " <=> ";
  }
  std::cout << d.at(d.size() - 1) << std::endl;
}

void dequeProjExe()
{
  std::deque<int> d1 {1, 2, 3, 4, 5};
  std::deque<double> d2 (4, 0);
  
  displayDeque(d1);
  
  d1.push_back(10);
  d1.push_back(20);
  d1.push_front(30);
  d1.push_front(40);
  
  displayDeque(d1);
  displayDeque(d2);
  
  d2.clear();
  std::copy(d1.begin(), d1.end(), std::front_inserter(d2));
  displayDeque(d2);
}
