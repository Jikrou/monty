Monty Program

The Monty program is an interpreter for Monty ByteCodes files. Monty is a scripting language that is first compiled into Monty ByteCodes (just like Python). It relies on a unique stack, with specific instructions to manipulate it.

Installation

To use the Monty program, you'll need to compile it from source. Here's how:

Clone the Monty repository:
git clone https://github.com/jikrou/monty

Navigate to the Monty directory:
cd monty

Compile the program using GCC:
Copy code

gcc -Wall -Werror -Wextra -pedantic *.c -o monty

Usage
Once compiled, you can use the Monty interpreter to execute Monty ByteCodes files. Here's how to run the program:

./monty file.m
Replace file.m with the path to your Monty ByteCodes file.

Supported Instructions

1. push
The push instruction pushes an integer onto the stack.

Usage: push <int>

Example:
push 1
push 2

2. pall
The pall instruction prints all the values on the stack.

Usage: pall

Example:
pall

3. pint
The pint instruction prints the value at the top of the stack.

Usage: pint

Example:
pint

4. pop
The pop instruction removes the top element of the stack.

Usage: pop

Example:
pop

5. swap
The swap instruction swaps the top two elements of the stack.

Usage: swap

Example:
swap

6. add
The add instruction adds the top two elements of the stack.

Usage: add

Example:
add

7. nop
The nop instruction does nothing.

Usage: nop

Example:
nop

8. sub
The sub instruction subtracts the top element of the stack from the second top element.

Usage: sub

Example:
sub

9. div
The div instruction divides the second top element of the stack by the top element.

Usage: div

Example:
div

10. mod
The mod instruction computes the remainder of the division of the second top element of the stack by the top element.

Usage: mod

Example:
mod

Comment Handling

Monty supports comments in Monty bytecode files.
Comments are lines starting with the '#' character.
The Monty program ignores comments during execution.
To ignore a line entirely, ensure the '#' character is the first non-whitespace character on the line.
Lines with leading whitespace before the '#' character will not be interpreted as comments and will be processed as regular lines of code.
Comments can be used for adding explanatory notes, documentation, or disabling specific instructions temporarily.

Example of comments in a Monty bytecode file:
#This is a comment explaining the purpose of the following code
push 10
push 20
#The next line pops the element from the stack
pop

Contributors
Jikrou
