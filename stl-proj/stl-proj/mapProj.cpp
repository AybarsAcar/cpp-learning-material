//
//  mapProj.cpp
//  stl-proj
//
//  Created by Aybars Acar on 14/1/21.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void displayMap(const std::map<K, V> &m)
{
  std::cout << "{\n";
  for (auto &elem : m)
  {
    std::cout << "\t" << elem.first << ": " << elem.second << ",\n";
  }
  std::cout << "}" << std::endl;
}

void mapProjExe()
{
  std::map<std::string, int> m1
  {
    {"Aybars", 28},
    {"Shuang", 23},
    {"Zuhre", 20},
    {"Isil", 54}
  };
  
  displayMap(m1);
  
  m1.insert(std::make_pair("Hello", 2021));
  
  m1["World"] = 10;
  m1["World"]++;
  
  displayMap(m1);
  
  m1.erase("World");
  displayMap(m1);
  
  auto pair = m1.find("Aybars");
  std::cout << pair->first << std::endl;
  std::cout << pair->second << std::endl;
}
