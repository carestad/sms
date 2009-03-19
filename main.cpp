#include <iostream>
#include <string>
#include "providers/eurobate.h"

void print_usage(std::string name)
{
  std::cout << "Usage: " << name << " eurobate <from> <to> <message>" << std::endl;
  std::cout << "Usage: " << name << " 1881 <username> <password> <to> <message>" << std::endl;
}

int main(int argc, char **argv)
{

  if (argc <= 1) {
    print_usage(argv[0]);
    return 0;
  }
  
  if ((std::string)argv[1] == "eurobate") {
    if (argc != 5) {
      print_usage(argv[0]);
      return 1;
    }

    Eurobate eurobate;
    if (eurobate.send(argv[3], argv[2], argv[4]) == false)
      return 1;
  } else if ((std::string)argv[1] == "1881") {
    std::cout << "1881 not implemented yet" << std::endl;
    return 1;
  }

  return 0;
}
