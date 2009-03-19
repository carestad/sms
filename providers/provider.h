#ifndef __PROVIDER_H
#define __PROVIDER_H

#include <string>
#include "curl/curl.h"

class Provider
{
 public:
  virtual void setup(std::string username, std::string password) = 0;
  virtual bool send(std::string to, std::string from, std::string message) = 0;
};

#endif // __PROVIDER_H
