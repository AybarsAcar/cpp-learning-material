//
//  Player.hpp
//  oop
//
//  Created by Aybars Acar on 7/1/21.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <iostream>

/**
 * Player class
 */
class Player
{
public:                           // everything is public
  std::string name;
  int health {100};               // with a default value
  int xp;
  
  /**
   * Constructor with the name
   * with constructor initialisation - used for simple assignment constructors
   * this is just another constructor way simple no logic constructors
   * this executes faster so use this for simple pojos!
   */
  Player(std::string name)
  : name {name}, xp {1}
  {
  }
  
  /**
   * this is the normal assignment way
   * this is less efficient for simple assignment constructors
   */
  Player(std::string name, int xp)
  {
    this -> name = name;
    this -> xp = xp;
  }
  
  void talk(std::string);
  
  bool isDead();
  
  /**
   * Copy constructor signature
   * implemented in Player.cpp
   */
  Player(Player const &source);
  
  /**
   * destructor
   */
  ~Player()
  {
    std::cout << "Destructor is called for " << name << std::endl;
  }
};

#endif /* Player_hpp */
