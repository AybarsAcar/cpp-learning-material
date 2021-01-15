//
//  Move.hpp
//  oop
//
//  Created by Aybars Acar on 10/1/21.
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>

/**
 * Class that has a move constructor
 */
class Move
{
private:
  int *data;
  
public:
  Move(int d);                              // constructor
  Move(const Move &source);                 // copy constructor
  Move(Move &&source) noexcept;             // move construcotor
  ~Move();                                  // destructor
  
  void setData(int d);
  int getData();
};

#endif /* Move_hpp */
