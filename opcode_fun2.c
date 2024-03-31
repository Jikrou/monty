#include "monty.h"
/**
 * divi - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number being evaluated from the Monty file
*/
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int num;

	if (top == NULL || top->next == NULL)
	{
		print_err("can't div, stack too short", line_number);
	}
	if (top->n == 0)
	{
		print_err("division by zero", line_number);
	}

	num = top->next->n / top->n;
	pop(stack, line_number);

	top = *stack;
	top->n = num;
}
