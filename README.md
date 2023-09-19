# simple shell project
- In this project we are tasked to write a simple UNIX command interpreter like `sh` 
(`/bin/sh`)
___
- We have 5 mandatory task:

1. Handle command lines without arguments
2. Handle command lines with arguments
3. Handle the PATH
4. Implement the exit built-in
5. Implement the env built-in
  ___
- [simple shell](https://github.com/MOHAMedelhennawy/simple_shell/blob/master/simpe_shell.c) this is the main file for project 
- [excute command](https://github.com/MOHAMedelhennawy/simple_shell/blob/master/execve_path.c)
- [search in path](https://github.com/MOHAMedelhennawy/simple_shell/blob/master/search_in_path.c)
___
- [x] This project follow betty style for a clean code .
## Output
- This program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to argv[0]
- This shell work in interactive mode and in non-interactive mode

## Compilation  and Run
- This shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- Run: `./hsh`
## System calls
- In this project we use the following system call:

`access` 
`execve` 
`exit` 
`fork`
`free`
`getline`
`getpid`
`isatty`
`malloc`
`perror`
`read`
`stat`
`strtok`
`wait`

## Learning Objectives
- In this project we learned:
- [x] Who designed and implemented the original Unix operating system
- [x] Who wrote the first version of the UNIX shell
- [x] Who invented the B programming language (the direct predecessor to the C programming language)

- [x] Who is Ken Thompson
- [x] How does a shell work
- [x] What is a pid and a ppid
- [x] How to manipulate the environment of the current process

- [x] What is the difference between a function and a system call
- [x] How to create processes

- [x] What are the three prototypes of main

- [x] How does the shell use the PATH to find the programs

- [x] How to execute another program with the execve system call

- [x] How to suspend the execution of a process until one of its children terminates
- [x] What is EOF / “end-of-file”?

## Contributors
- [x] This project was done by team of two people:
- [Kareem Hany](https://github.com/Kareem1715) 
- [Mohamed Elhennawy](https://github.com/MOHAMedelhennawy)
