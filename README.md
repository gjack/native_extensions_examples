# Examples for native Ruby C ad C++ extensions

## C extension

After cloning the repo, cd into the `greeter` directory and run the following command to generate the Make file:

```
ruby extconf.rb
```

Once the Makefile has been created, compile the code by running

```
make
```

Once the code has been compiled, you can require and use the extension in irb

```
irb> require "./greeter"
irb> Greeter.say_hello "Bob"
```

## C++ extension

The extension was made using a Ruby interface for C++ extensions called [Rice](https://github.com/ruby-rice/rice). You will need to install this gem before being able to create a Make file and compile the code for this extension. Once you have installed the gem, the instructions for compiling the code are very similar to the ones for the C extension.

After cloning the repo, cd into the `greeter_wrapped` directory and run the following command to generate the Make file:

```
ruby extconf.rb
```

Once the Makefile has been created, compile the code by running

```
make
```

Once the code has been compiled, you can require and use the extension in irb

```
irb> require "./greeter_wrapped"
irb> GreeterWraped.say_hello "Bob"
```

### Wrapped methods

Notice the code inside `Init_greeter_wrapped`. The following version will declare a method called `say_hello` wrapping the `say_hello` method we implemented above in this same file, which does some additional work and calls methods of the C++ library.

```
Class rb_cGreeter = define_class("Greeter")
  .define_method("say_hello", &say_hello);
```

On the other hand, this code will simply wrap the existing `greet` method of the C++ library as the `say_hello` Ruby method, without adding anything to it.

```
Data_Type<Greeter> rb_Greeter = define_class<Greeter>("Greeter")
  .define_constructor(Constructor<Greeter>())
  .define_method("say_hello", &Greeter::greet);
```