//
//  IPrintable.cpp
//  inheritance-polymorphism
//
//  Created by Aybars Acar on 12/1/21.
//

#include "IPrintable.hpp"

std::ostream &operator<<(std::ostream &out, const IPrintable &obj)
{
  obj.print(out);
  return out;
}
