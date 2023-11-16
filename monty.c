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
	char *line = NULL;
	size_t len = 0;
	ssize_t cread;
	int line_number = 1;
	char *opcode;
	char *token[3];
	int idx;
	stack_t *stack = NULL;
	stack_t **stack_ptr = &stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glob_v.stream = fopen(argv[1], "r");
	if (glob_v.stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((cread = getline(&line, &len, glob_v.stream)) != -1)
	{
		trim_spaces(line); /* trim leading and trailing white space */

		/* skip blank lines and comments */
		if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
		{
			line_number++;
			continue;
		}
		token[0] = strtok(line, " ");
		opcode = token[0];

		idx = 0;
		while (token[idx] != NULL && idx < 1)
		{
			idx++;
			token[idx] = strtok(NULL, " ");
		}
		if (token[1] != NULL)
		{
			if (is_digit(token[1]) == 0)
				token[1] = NULL;
		}
		/* validate opcodes */
		if (!validate_ops(opcode))
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		execute(token[0], stack_ptr, token, line_number);
		line_number++;
	}
	free(line);
	fclose(glob_v.stream);
	exit(EXIT_SUCCESS);
}
