#ifndef __EUROBATE_H__
#define __EUROBATE_H__

#include "provider.h"
#include <string>

class Eurobate : public Provider
{
 public:
  void setup(std::string username, std::string password);
  bool send(std::string to, std::string from, std::string message);
};

#endif //__EUROBATE_H__
