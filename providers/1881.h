#include "provider.h"
#include <string>

class 1881 : public Provider
{
 public:
  void setup(string username, string password);
  void send(int to, string message);
};
