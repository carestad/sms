#ifndef __PROVIDER_H__
#define __PROVIDER_H__

#include "provider.h"
#include <string>

class N1881 : public Provider
{
 public:
  void setup(std::string username, std::string password);
  bool send(int to, std::string message);
};

#endif //__PROVIDER_H__
