//
//  Deep.hpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#ifndef Deep_hpp
#define Deep_hpp

#include <stdio.h>

/**
 * Deep Class
 * does deep copying to avoid the problems in the Shallow copy
 */
class Deep
{
private:
  int *data;
  
public:
  Deep(int d);
  Deep(const Deep &source);
  ~Deep();
  
  void setData(int d);
  int getData();
};

#endif /* Deep_hpp */
