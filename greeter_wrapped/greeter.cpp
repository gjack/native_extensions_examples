#include <iostream>
#include "greeter.h"
  
void Greeter::greet(std::string str) {
  std::cout << "Hello " << str << std::endl;
}

void Greeter::complain(void) {
  std::cout << "Calling for complains" << std::endl;
}