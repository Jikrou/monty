#include "monty.h"

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[]) {
  stack_t *stack = NULL;
  FILE *mofile;
  unsigned int line_number = 0;
  char line[100]; // Assuming each line has at most 100 characters
  char *opcode;
  char *argm;
  int value;

  if (argc != 2) {
    printf("USAGE: %s file\n", argv[0]);
    return (EXIT_FAILURE);
  }

  mofile = fopen(argv[1], "r");
  if (mofile == NULL) {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    return (EXIT_FAILURE);
  }
  while (fgets(line, sizeof(line), mofile) != NULL) {
    line_number++; // Increment line number

    opcode = strtok(line, " \t\n");
    argm = strtok(NULL, " \t\n");
    if (opcode == NULL || strlen(opcode) == 0)
      continue;

    if (strcmp(opcode, "push") == 0) {
      if (argm == NULL || !isdigit(argm[0])) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
      }
      value = atoi(argm);
      push(&stack, value);
    } else
      check_instructions(stack, opcode, argm, line_number);
  }
  fclose(mofile);
  free_stack(stack);
  return (0);
}
