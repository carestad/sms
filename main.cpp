#include <iostream>
#include <string>
#include "providers/eurobate.h"

int main(int argc, char **argv)
{

  if (argc != 5) {
    std::cout << "Usage: " << argv[0] << " username password to message" << std::endl;
    return 0;
  }
  
  Eurobate eurobate;
  eurobate.setup(argv[1], argv[2]);
  if (eurobate.send(argv[3], argv[1], argv[4]) == false)
    return 1;

  return 0;
}
