#include "monty.h"
/**
 * push - The opcode push pushes an element to the stack
 * @stack: double pointer to the top of the stakc
 * @data: the value to be pushed
 */
void push(stack_t **stack, int data)
{
stack_t *newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(EXIT_FAILURE);
}
newNode->n = data;
newNode->prev = NULL;
newNode->next = *stack;

if (*stack != NULL)
{
(*stack)->prev = newNode;
}

*stack = newNode;
}
/**
 * pall - The opcode pall prints all the values on the stack
 * starting from the top of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: the line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *cur;
(void)line_number;

if (*stack == NULL)
{
exit(0);
}

cur = *stack;
while (cur != NULL)
{
printf("%d\n", cur->n);
cur = cur->next;
}
}
/**
 * pint - The opcode pint prints the value at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to the top of stack
 * @line_number: the line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
stack_t *cur;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
cur = *stack;
if (cur != NULL)
printf("%d\n", cur->n);
}

/**
 * pop - The opcode swap swaps the top two elements of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: the line number of the op
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *cur = *stack;

if (cur == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
*stack = cur->next;
if (*stack != NULL)
{
(*stack)->prev = NULL;
}
free(cur);
}
/**
 * print_err - print an error msg to the stderr
 * @err_msg: the msg to be printed
 * @line_number: the line where the error occurd
*/
void print_err(const char *err_msg, unsigned int line_number)
{
	fprintf(stderr, "L%u: %s\n", line_number, err_msg);
	exit(EXIT_FAILURE);
}
