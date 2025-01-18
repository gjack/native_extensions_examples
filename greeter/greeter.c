#include <stdio.h>
#include <ruby.h>

VALUE greet(VALUE _self, VALUE str) {
  Check_Type(str, T_STRING);
  puts(StringValueCStr(str));
  printf("Hello %s\n", StringValueCStr(str));
  return Qnil;
}

void Init_greeter() {
  VALUE mod = rb_define_module("Greeter");

  rb_define_module_function(mod, "say_hello", greet, 1);
}