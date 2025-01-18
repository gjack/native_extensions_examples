#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include <iostream>
#include "greeter.h"

using namespace Rice;

void say_hello(VALUE self, String name) {
  std::string c_name = name.c_str();
  Greeter greeter;
  std::cout << "Doing other stuff in C++ and using methods of library" << std::endl;
  greeter.complain();
  greeter.greet(c_name);
  
}

extern "C"
void Init_greeter_wrapped()
{
  Class rb_cGreeter = define_class("Greeter")
    .define_method("say_hello", &say_hello);

  // Wrap original method
  // Data_Type<Greeter> rb_Greeter = define_class<Greeter>("Greeter")
  //   .define_constructor(Constructor<Greeter>())
  //   .define_method("say_hello", &Greeter::greet);
}