//
//  IPrintable.hpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 12/1/21.
//

#ifndef IPrintable_hpp
#define IPrintable_hpp

#include <stdio.h>
#include <iostream>

/**
 * IPrintable interface
 */
class IPrintable
{
  friend std::ostream &operator<<(std::ostream &out, const IPrintable &obj);
  
public:
  virtual void print(std::ostream &out) const = 0;
  virtual ~IPrintable() = default;
};

#endif /* IPrintable_hpp */
