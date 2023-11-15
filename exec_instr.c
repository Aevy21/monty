#include "monty.h"

/**
 * execute_instr - executes the instructions/functions
 * @opcode: pointer to an instruction
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void execute_instr(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int k;

	for (k = 0; instr[k].opcode; k++)
	{
		if (strcmp(opcode, instr[k].opcode) == 0)
		{
			instr[k].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
