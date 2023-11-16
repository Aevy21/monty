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
	char *buff[3];
	int idx;
	char *opcode;

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
		trim_spaces(glob_v.line); /* trim leading and trailing white space */

		/* skip blank lines and comments */
		if (glob_v.line[0] == '\0' || glob_v.line[0] == '\n' || glob_v.line[0] == '#')
		{
			line_number++;
			continue;
		}
		buff[0] = strtok(glob_v.line, " \n\t");
		opcode = buff[0];
		idx = 0;
		while (buff[idx] != NULL && idx < 1)
		{
			idx++;
			buff[idx] = strtok(NULL, " \n");
		}
		if (buff[1] != NULL && is_digit(buff[1]) == 0)
			buff[1] = NULL;

		/* validate opcodes */
		if (!validate_ops(opcode))
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		execute(buff[0], buff[1], line_number);
		line_number++;
	}
	free_stack();
	exit(EXIT_SUCCESS);
}
