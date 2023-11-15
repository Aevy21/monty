#define _POSIX_C_SOURCE 200809L
#include "monty.h"

int main(int argc, char **argv);
/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: an array of strings
 * Return: Always 0 Success
 */
int main(int argc, char **argv)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t cread;
	int line_number = 1;
	char *opcode, *token;
	stack_t *head = NULL;
	instruction_t instr;
	stack_t **stack = &head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((cread = getline(&line, &len, stream)) != -1)
	{
		token = strtok(line, " ");
		opcode = token;
		token = strtok(NULL, " ");

		instr.opcode = opcode;
		if (strcmp(opcode, "push") == 0)
		{
			if (token == NULL || !isdigit(*token))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			else
			{
				instr.val = atoi(token);
				instr.f = push;
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			instr.f = pall;
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			instr.f = pint;
		}
		else
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		instr.f(stack, line_number, instr.val);
		line_number++;
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

