Simple Shell Project
This is Shell program written in C, based on Thompson Shell.

Installation
Clone the local repository using GCC compiler.
https://github.com/Muoti5/simple_shell.git

Compilation
This is how the Shell will be compiled:
gcc -Wall -Werror -Wextra -pedantic -std=gnu8 *.c -o hsh

Testing
i. Interactive Mode
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

ii. Non-Interactive Mode
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$


