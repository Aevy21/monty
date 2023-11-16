#include "monty.h"

int execute(char *line, stack_t **stack, unsigned int line_num, FILE *stream);
/**
 * execute - executes the instructions/functions
 * @line: pointer to an instruction
 * @stack: pointer to a stack
 * @line_num: an integer
 * @stream: pointer to a file
 * Return: Nothing
 */
int execute(char *line, stack_t **stack, unsigned int line_num, FILE *stream)
{
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int j;
	int k = 0;
	char *tok, *endpt;

	tok = strtok(line, " \n\t");
	if (tok && tok[0] == '#')
	{
		free(line);
		return (0);
	}

	glob_v.arg = strtok(NULL, " \n\t");
	while (instr[k].opcode && tok)
	{
		if (strcmp(tok, instr[k].opcode) == 0)
		{
			if (strcmp(tok, "push") == 0)
			{
				if (!glob_v.arg || strcmp(glob_v.arg, "-") == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_num);
					fclose(stream);
					free(line);
					free_stack(*stack);
					exit(EXIT_FAILURE);
				}

				j = (glob_v.arg[0] == '-');
				while (glob_v.arg[j] != '\0')
				{
					if (!isdigit(glob_v.arg[j]))
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_num);
						fclose(stream);
						free(line);
						free_stack(*stack);
						exit(EXIT_FAILURE);
					}
					j++;
				}
				glob_v.val = strtol(glob_v.arg, &endpt, 10);
				if (*endpt != '\0')
				{
    				fprintf(stderr, "L%d: usage: push integer\n", line_num);
   					fclose(stream);
  					free(line);
  				 	free_stack(*stack);
   				 	exit(EXIT_FAILURE);
				}
				else
					push(stack, line_num);
			}
			else
			{
				instr[k].f(stack, line_num);
			}
			return (0);
		}
		k++;
	}
	if (tok && instr[k].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tok);
		fclose(stream);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
