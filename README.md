# MRuby Examples

MRuby examples to demonstrate usage.

## Compiling

### Get MRuby

Make sure to have [MRuby](https://mruby.org/) installed, see [here](https://github.com/mruby/mruby#how-to-get-mruby).

If you are on Linux chances are MRuby is already in the package repositories of your favorite distro! then you'll need to use
your distro specific package manager to install it. E.g:

APT:  
```console
sudo apt install libmruby-dev
```

DNF:  
```console
sudo dnf install mruby-devel
```

Pacman:  
```console
sudo pacman -S mruby
```

That will install all the development headers needed to use MRuby.

### Build

In the root of this repo:

```console
mkdir build && cd build
cmake ..
make
```

## Summary

Examples included here:

- [hello-world/](src/hello-world/)  
    Simple hello world
- [hello-file/](src/hello-file/)  
    Load ruby code from a file
- [pushing-variables/](src/pushing-variables/)  
    Push various datatypes to Ruby land
- [objects/](src/objects/)  
    Create classes/objects from C
- [checking-for-methods/](src/checking-for-methods/)  
    Try to find methods in Ruby land
- [call-methods/](src/call-methods/)  
    Calling methods in Ruby land from C land
- [using-cdata/](src/using-cdata/)  
    Encapsulate C-data in a ruby object
- [kwargs/](src/kwargs/)  
    Parse keyword arguments
- [blocks/](src/blocks)  
    Use blocks from various ways

## Credits

Credits where due, here are some helpful articles/post/resources that helped
me to learn how to use MRuby:

- [Executing Ruby code with MRuby](https://mruby.org/docs/articles/executing-ruby-code-with-mruby.html)
- [MRuby GUI series](https://dev.to/roryo/a-new-smalltalk-style-environment-for-ruby-5f5c)

## License

All the examples found here are licensed under the [MIT license](/LICENSE).
