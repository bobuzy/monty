# Monty Project at ALX-SE School

This project is part of the ALX-SE School curriculum and focuses on the implementation of stacks and queues using C programming language. The goal of the project is to create an interpreter for Monty ByteCodes files.

## Project Details

- Weight: 2
- Team Members: Goodness Atunde, Benedict Abudu

## Learning Objectives

- Explain the concepts of LIFO (Last In, First Out) and FIFO (First In, First Out)
- Understand the purpose and usage of stacks and queues
- Identify common implementations of stacks and queues
- Recognize the most common use cases of stacks and queues
- Properly use global variables in C programming

## Requirements

- Allowed editors: vi, vim, emacs
- Compilation: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
- Output: Any output must be printed on stdout, and any error message must be printed on stderr
- Coding Style: Your code should follow the Betty style guidelines
- Maximum Functions per File: 5
- Maximum Global Variables: 1
- Header File: monty.h should contain the prototypes of all functions
- Header File Guard: All header files should be include guarded

## The Monty Language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack with specific instructions to manipulate it. Monty byte code files have the .m extension and contain one instruction per line. The monty program runs the bytecodes line by line and stops if either every line is executed properly, an error is found in the file, or an error occurs.

## Usage

To run the Monty interpreter, use the following command:

```
monty <file>
```
