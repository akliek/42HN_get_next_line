# 42HN_get_next_line
Summary:

The aim of this project is to make code a function that returns a line, read from a file descriptor.

Foreword:

This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming: static variables.

Links:

Wikipedia about static variables: https://en.wikipedia.org/wiki/Static_variable

Subject PDF: https://github.com/akliek/42HN_get_next_line/blob/master/en.subject.pdf

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# How doe's it work?

First argument - it is a file descriptor of file where you reading lines. Second argument - it is an address to string where line will be stored.

# How to use?
For using "get_next_line" function in your projects include get_next_line.h header and compile it with following command:
```
gcc your_files.c <path to get_next_lien.c> <path to get_next_line_utils.c> -D BUFFER_SIZE="number_of_buffer_size"
```
To avoid defining of buffer size each timr during compilation you can define it in get_next_line.c header with adding following command into it:
```
# define BUFFER_SIZE "number_of_buffer_size"
```
