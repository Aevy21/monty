#define _POSIX_C_SOURCE 200809L
#include "monty.h"

int main(int argc, char **argv);
/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: an array of strings
 * Return: Always 0 Success
 */
int main(int argc, char *argv[])
{
	char *line;
	FILE *stream;
	size_t len = 0;
	ssize_t cread = 0;
	stack_t *stack = NULL;
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	glob_v.stream = stream;

	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((cread = getline(&line, &len, stream)) != -1)
	{
		glob_v.line = line;
		line_number++;

		if (cread > 0)
		{
			execute(line, &stack, line_number, stream);
		}
		free(line);
		line = NULL;
	}
	free_stack(stack);
	fclose(stream);
	return (0);
}
