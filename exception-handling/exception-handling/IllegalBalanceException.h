//
//  IllegalBalanceException.h
//  exception-handling
//
//  Created by Aybars Acar on 12/1/21.
//

#include <exception>

#ifndef IllegalBalanceException_h
#define IllegalBalanceException_h

class IllegalBalanceException : public std::exception
{
public:
  IllegalBalanceException() noexcept = default;
  ~IllegalBalanceException() = default;
  
  virtual const char *what() const noexcept
  {
    return "Balance can not be less than 0";
  }
};


#endif /* IllegalBalanceException_h */
