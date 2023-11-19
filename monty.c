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
	size_t len = 0;
	ssize_t cread;
	unsigned int line_number = 1;
	char *delims = " \t\n";
	char *opcode, *arg;
	char *token;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glob_v.stream = fopen(argv[1], "r");
	if (glob_v.stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((cread = getline(&glob_v.line, &len, glob_v.stream)) != -1)
	{
		/* check spaces */
		if (check_spaces() == 1)
		{
			line_number++;
			continue;
		}
		token = strtok(glob_v.line, delims);
		if (token == NULL)
		{
			line_number++;
			continue;
		}
		opcode = token;
		arg = strtok(NULL, delims);
		/* execute instructions */
		execute(opcode, arg, line_number);
		line_number++;
	}
	free(glob_v.line);
	free(stack);
	fclose(glob_v.stream);
	return (0);
}
