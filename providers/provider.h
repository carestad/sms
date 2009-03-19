#ifndef __PROVIDER_H
#define __PROVIDER_H

#include <string>

class Provider
{
 protected:
  string username;
  string password;
 public:
  virtual void setup(string username, string password) = 0;
  virtual void send(int to, string message) = 0;
};

#endif // __PROVIDER_H
