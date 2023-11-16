#include "monty.h"

/**
 * execute - executes the instructions/functions
 * @opcode: pointer to an instruction
 * @sp: pointer to a stack
 * @tok: an array of tokens
 * @line_number: an integer
 * Return: Nothing
 */
void execute(char *opcode, stack_t **sp, char **tok, unsigned int line_number)
{
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int k = 0;

	while (instr[k].opcode != NULL)
	{
		if (strcmp(opcode, instr[k].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if ((!is_digit(tok[1])) || tok[1] == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				glob_v.val = atoi(tok[1]);
				push(sp, line_number);
			}
			else
			{
				instr[k].f(sp, line_number);
			}
			return;
		}
		k++;
	}
	fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
