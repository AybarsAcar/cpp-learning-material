//
//  Player.cpp
//  oop
//
//  Created by Aybars Acar on 7/1/21.
//

#include "Player.hpp"
#include <iostream>


void Player::talk(std::string phrase)
{
  std::cout << this -> name << " says " << phrase << std::endl;
}

bool Player::isDead()
{
  return health <= 0;
}

/**
 * Copy constructor implementation
 */
Player::Player(const Player &source)
: name{source.name}, health{source.health}, xp{source.xp}
{
}
