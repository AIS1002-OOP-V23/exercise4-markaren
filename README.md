# AIS1002 Exercise 4 - week 6

This lab is about smart-pointers, RAII, memory leaks and memory consumption.

> The amount of code needed to be written is minimal in this exercise. <br>
> Make sure you look at the code and read the attached comments and hints.

## Exercise 1

Implement the following functions located in `include/exercises/exercise1.hpp`: 
```cpp
std::string SharedString::str()
void SharedString::update(const std::string&)

std::pair<SharedString, SharedString> shareMe(std::unique_ptr<std::string>&)
```


## Exercise 2

Calling the function `testWillCallThisFunction` located in `include/exercises/exercise2.hpp` results in a memory leak. <br>

__Locate and fix the underlying issue of the memory leak.__

## Exercise 3

The code located in `include/exercises/exercise3.hpp` might use more memory than __intended__. <br>
Basically, there is a bug hidden in there. What is the code indicating and what is actually happening?
A solution will only need to change the logic in a single function.


## Finished early?

Clone [threepp](https://github.com/markaren/threepp), read the code or just have fun creating 3D graphics.
The project relies heavily on smart pointers.