#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s {
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

bool check_instructions(stack_t **stack, char *opcode, char *arg,
                        unsigned int linenum);
void push(stack_t **stack, int data);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mult(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void print_err(const char *err_msg, unsigned int line_number);
void free_stack(stack_t *stack);
#endif /* MONTY_H */
