#ifndef __PROVIDER_H
#define __PROVIDER_H

#include <string>

class Provider
{
 protected:
  std::string username;
  std::string password;
 public:
  virtual void setup(std::string username, std::string password) = 0;
  virtual bool send(int to, std::string message) = 0;
};

#endif // __PROVIDER_H
