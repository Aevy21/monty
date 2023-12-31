#include "monty.h"

/**
 * execute - executes the instructions/functions
 * @op: pointer to an instruction
 * @arg: pointer to a the instr arg
 * @line_number: an integer
 * Return: Nothing
 */
void execute(char *op, char *arg, unsigned int line_number)
{
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_f},
		{"mul", mul_f},
		{"mod", mod_f},
		{NULL, NULL}
	};
	int k;

	for (k = 0; instr[k].opcode != NULL; k++)
	{
		if (strcmp(op, instr[k].opcode) == 0)
		{
			if (strcmp(op, "push") == 0)
			{
				if ((!is_digit(arg)) || arg == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				glob_v.val = atoi(arg);
			}
			instr[k].f(&glob_v.ptr, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
