//
//  InsufficientFundsException.h
//  exception-handling
//
//  Created by Aybars Acar on 12/1/21.
//

#include <exception>

#ifndef InsufficientFundsException_h
#define InsufficientFundsException_h

class InsufficientFundsException: public std::exception
{
public:
  InsufficientFundsException() noexcept = default;
  ~InsufficientFundsException() = default;
  
  virtual const char *what() const noexcept
  {
    return "Insufficient funds to proceed with the withdrawal";
  }
};


#endif /* InsufficientFundsException_h */
