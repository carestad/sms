#ifndef __N_1881_H__
#define __N_1881_H__

#include "provider.h"
#include <string>

class N1881 : public Provider
{
 public:
  void setup(std::string username, std::string password);
  bool send(std::string to, std::string from, std::string message);
};

#endif //__N_1881_H__
