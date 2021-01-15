//
//  listProj.cpp
//  stl-proj
//
//  Created by Aybars Acar on 14/1/21.
//

#include <stdio.h>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <forward_list>

template <typename T>
void displayList(std::list<T> &l)
{
  std::cout << "NULL <=> " << std::endl;
  for (auto elem : l)
  {
    std::cout << elem << " <=> ";
  }
  std::cout << " NULL" << std::endl;
}

template <typename T>
void displayForwardList(std::forward_list<T> &fl)
{
  for (auto elem : fl)
  {
    std::cout << elem << " -> ";
  }
  std::cout << " NULL" << std::endl;
}

void listProjExe()
{
//  doubly linked list
  std::list<std::string> strList {"Aybars", "Shuang", "Zuhre", "Isil"};
  
  strList.push_front("Hello");
  
  std::cout << strList.front() << std::endl;
  std::cout << strList.back() << std::endl;
  
  displayList(strList);
  
//  singly linked list
  std::forward_list<int> list1 {1, 2, 3, 4, 5, 6};
  list1.push_front(10);
  
  std::cout << list1.front() << std::endl;
  list1.pop_front();
  std::cout << list1.front() << std::endl;
  list1.pop_front();
  std::cout << list1.front() << std::endl;
  
  displayForwardList(list1);

  auto it = std::find(list1.begin(), list1.end(), 4); // it at position 3
  
  std::advance(it, -2); // moves the pointers to 2 nodes right
  
  std::cout << *it << std::endl;
}
