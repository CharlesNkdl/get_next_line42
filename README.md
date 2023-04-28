# get_next_line ![Grade](https://img.shields.io/badge/Grade-125/100-brightgreen)

This is the `get_next_line` project from 42 School, which provides a function for reading a line from a file descriptor.

## Description

The `get_next_line` function reads the next line from a file descriptor and returns it as a `char *`. The function can be called repeatedly to read successive lines from the same file descriptor.

### Bonus

The `get_next_line` project has a bonus part, which requires the function to be able to handle multiple file descriptors simultaneously.

## Usage

To use `get_next_line`, call the function with a file descriptor and a pointer to a `char *`. The function will read the next line from the file descriptor and return it as a `char *` in the `line` pointer. The function should be called repeatedly to read successive lines from the same file descriptor.

### `open` Function

The `open` function is a system call used to open a file and return a file descriptor, which can be used in other I/O functions such as `read` and `write`. The function takes a filename as a string, a set of flags to specify how the file should be opened, and an optional mode argument that sets the file's permissions if it needs to be created.

### `read` Function

The `read` function is used to read data from a file descriptor into a buffer. The function takes a file descriptor, a pointer to a buffer, and the maximum number of bytes to read. The function returns the number of bytes read, or -1 if an error occurred.

### Static Variable

A static variable is a variable that is defined and initialized only once in a program and retains its value throughout the program's execution. Static variables are declared with the `static` keyword and can be used in functions or global scope.

In C, static variables declared in a function retain their values between function calls, meaning they are not reinitialized on subsequent calls. Static variables declared in global scope are initialized to zero by default, but can be explicitly initialized to a specific value.

Static variables are commonly used in situations where a value needs to be shared between multiple function calls or where a variable needs to retain its value across multiple function calls without being passed as a parameter or stored in memory.

# How do my program work

It works around 3 functions :
  * One to read the file onto a buffer, put it in the static char*, then analyse it until there is a newline in it.
  * Then, extract this line in a dynamically allowed char*, which will be returned
  * Before returning the char*, we will delete it from the static so the program won't be keeping all this information
  
    

