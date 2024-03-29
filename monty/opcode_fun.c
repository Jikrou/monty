#include "monty.h"

instruction_t instructions[] = {
    {"pall", *pall}, {"pint", *pint}, {"pop", pop},
    {"swap", *swap}, {"add", *add},   {"nop", *nop},

};
/**
 * check_instructions - Checks if the given opcode matches any
 * supported instruction and executes the corresponding function.
 * @stack: Pointer to the beginning of the stack.
 * @opcode: String representing the opcode of the instruction to be executed.
 * @arg: Argument associated with the instruction (if any).
 * @line_number: Line number being executed.
 */
void check_instructions(stack_t *stack, char *opcode, char *arg,
                        unsigned int line_number) {
  size_t i;
  if (stack != NULL || opcode != NULL) {
    for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++) {
      if (strcmp(opcode, instructions[i].opcode) == 0) {
        instructions[i].f(&stack, line_number);
        return;
      }
    }
  }

  fprintf(stderr, "Error at line %u: Unknown instruction %s\n", line_number,
          opcode);
}
/**
 * push - The opcode push pushes an element to the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: the line number of the opcode
 */
void push(stack_t **stack, int data) {
  stack_t *newNode = malloc(sizeof(stack_tt));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->n = data;
  newNode->prev = NULL;
  newNode->next = *stack;

  if (*stack != NULL) {
    (*stack)->prev = newNode;
  }

  *stack = newNode;
}
/**
 * pall - The opcode pall prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: the line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number) {
  stack_t *cur;

  if (*stack == NULL) {
    printf("Stack is empty\n");
    return;
  }

  cur = *stack;
  while (cur != NULL) {
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
void pint(stack_t **stack, unsigned int line_number) {
  stack_t *cur;

  if (*stack == NULL) {
    fprintf(stderr, "L%u : can't pint, stack empty\n", line_number);
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
void pop(stack_t **stack, unsigned int line_number) {
  stack_t *cur = *stack;

  if (cur == NULL) {
    fprintf(stderr, "L%u : can't pop an empty stack\n", line_number);
    exit(EXIT_FAILURE);
  }
  *stack = cur->prev;

  if (*stack != NULL) {
    (*stack)->next = NULL;
  }
  free(cur);
}
