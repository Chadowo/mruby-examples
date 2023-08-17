# MRuby Examples

MRuby examples to demonstrate usage

## Compiling

### Get MRuby

Make sure to have [MRuby](https://mruby.org/) installed, see [here](https://github.com/mruby/mruby#how-to-get-mruby).

If you are on linux chances are MRuby is already in the package repositories of your distro! then you'll need to use
your distro specific package manager to install it, in Ubuntu for example:

`sudo apt install libmruby-dev`

That will install all the development headers for MRuby.

### Build

In the root of this repo:

```
mkdir build && cd build
cmake ..
make
```

The final executables will be found in the bin/ directory relative to the repo
root.

## Summary

Examples found here in this project:

- hello-world/  
    Simple hello world

- hello-file/  
    Load ruby code from a file

- pushing-variables/  
    Push various datatypes to Ruby land

- objects/  
    Create classes/objects from C

- checking-for-methods/  
    Try to find methods in Ruby land

- call-methods/  
    Calling methods in Ruby land from C land

- using-cdata/  
    Encapsulate C-data in a ruby object

## Credits

Credits where due, here are some helpful articles/post/resources that helped
me to learn how to use MRuby:

- [Executing Ruby code with MRuby](https://mruby.org/docs/articles/executing-ruby-code-with-mruby.html)
- [MRuby GUI series](https://dev.to/roryo/a-new-smalltalk-style-environment-for-ruby-5f5c)
