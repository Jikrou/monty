#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number being executed.
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
int temp;

if (top == NULL || top->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = top->n;
top->n = top->next->n;
top->next->n = temp;
}

/**
 * add - The opcode add adds the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: Line number being executed.
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
int sum;
if (top == NULL || top->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
sum = top->n + top->next->n;

pop(stack, line_number);

top = *stack;
top->n = sum;
}
/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: double pointer to the beginning of the stack.
 * @line_number: Line number being executed.
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
/**
 * free_stack - a function that frees all the stack
 * @head: pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
stack_t *curr;

while (head != NULL)
{
curr = head->next;
free(head);
head = curr;
}
}
/**
 * sub - The opcode sub subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number with the instruction to be executed
*/
void sub(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
int subtra;

if (top == NULL || top->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
subtra = top->n - top->next->n;
pop(stack, line_number);

top = *stack;
top->n = abs(subtra);
}
