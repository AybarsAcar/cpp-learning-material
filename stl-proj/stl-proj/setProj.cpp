//
//  set.cpp
//  stl-proj
//
//  Created by Aybars Acar on 14/1/21.
//

#include <stdio.h>
#include <iostream>
#include <set>

template <typename T>
void displaySet(std::set<T> &s)
{
  std::cout << "[ ";
  for (auto elem : s)
  {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void setProjExe()
{
  std::set<int> s1 {1, 3, 4, 6, 2, 5, 5, 25, 10};
  displaySet(s1);
  
  std::cout << "12 is in the set times: " << s1.count(12) << std::endl;
  
  auto it = s1.find(5);
  if (it != s1.end())
  {
    std::cout << "Found: " << *it << " at " << &it << std::endl;
  }
  
//  erase 25 from the list
//  we must get an iterator and point to that element
  s1.erase(s1.find(25));
  displaySet(s1);
  
  std::set<char> s2 {'A', 'B', 'c', 'a'};
  displaySet(s2);
  
  auto result = s2.insert('C');     // returns a std::pair<iterator, bool>
  auto result2 = s2.insert('c');
  displaySet(s2);
  
  std::cout << std::boolalpha;
  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "secont: " << result.second << std::endl;
  
  std::cout << "first: " << *(result2.first) << std::endl;
  std::cout << "secont: " << result2.second << std::endl;
  
}
