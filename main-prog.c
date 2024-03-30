#include "monty.h"
static instruction_t instructions[] = {
	{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
	{"add", add}, {"nop", nop}, {"sub", sub},
	};

/**
 * main - Entry point of the monty interpreter
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings
 * Return: 0 on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	unsigned int line_number = 0;
	char line[100];
	char *opcode;
	char *ar;
	bool status = true;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		ar = strtok(NULL, " \t\n");
		if (opcode != NULL && strlen(opcode) > 0)
		{
			status = check_instructions(&stack, opcode, ar, line_number);
		}
		else
			continue;
	}
	fclose(file);
	free_stack(stack);

	if (status)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
/**
 * check_instructions - Checks if the given opcode mathes any
 * supported instruction and executes the corresponding function.
 * @stack: double pointer to the stack
 * @opcode: string representing the opcoe of the instruction to be executed.
 * @arg: argument associated with the instruction (if any)
 * @line_number: line number being executed.
 * Return: true if opcode is found, fakse otherwise
*/
bool check_instructions(stack_t **stack, char *opcode, char *arg,
unsigned int line_number)
{
	size_t i;
	int value = 0;

	if (stack == NULL || opcode == NULL)
	{
		fprintf(stderr, "L%u: Missing stack or opcode\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL || !isdigit(arg[0]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(arg);
		push(stack, value);
		return (true);
	}
	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (true);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
