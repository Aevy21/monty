#define _POSIX_C_SOURCE 200809L
#include "monty.h"
int val;

int main(int argc, char **argv);
/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: an array of strings
 * Return: Always 0 Success
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t cread;
	int line_number = 1;
	char *opcode, *token;
	stack_t *head = NULL;
	stack_t **stack = &head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((cread = getline(&line, &len, stream)) != -1)
	{
		trim_spaces(line); /* trim leading and trailing white space */

		/* skip blank lines and comments */
		if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
		{
			line_number++;
			continue;
		}
		token = strtok(line, " ");
		opcode = token;
		token = strtok(NULL, " ");

		if (token != NULL)
		{
			val = atoi(token);
		}
		/* validate opcodes */
		if (!validate_ops(opcode))
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		if (isdigit(opcode[2]) || opcode[2] == '\0')
		{
			push(stack, line_number);
		}
		else
		{
			execute_instr(opcode, stack, line_number);
		}

		line_number++;
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
