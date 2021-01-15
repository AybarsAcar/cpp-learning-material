//
//  Item.h
//  stl-proj
//
//  Created by Aybars Acar on 13/1/21.
//

#include <string>
#include <iostream>

#ifndef Item_h
#define Item_h

template <typename T>
class Item {
  friend std::ostream &operator<<(std::ostream &out, const Item &p)
  {
    out << "name: " << p.name << ", value: " << p.value;
    return out;
  }
  
  std::string name;
  T value;
  
public:
  Item(std::string name, T value) : name(name), value(value) {}
  std::string getName() { return name; }
  T getValue() { return value; }
};

#endif /* Item_h */
