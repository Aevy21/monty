#include "monty.h"

/**
 * trim_spaces - removes whitespaces
 * @str: pointer to a string
 * Return: Nothing
 */
void trim_spaces(char *str)
{
	ssize_t len;

	if (str == NULL)
		return;

	while (isspace(*str))
		str++;

	len = strlen(str);
	while (len > 0 && isspace(str[len - 1]))
		str[--len] = '\0';
}

/**
 * validate_ops - validates opcodes
 * @opcode: pointer to an opcode
 * Return: Always 0 Success
 */
int validate_ops(const char *opcode)
{
	size_t k;
	const char *valid_opcodes[] = {"push", "pall", "pint", "pop"};

	if (opcode == NULL || opcode[0] == '\0')
		return (1);

	for (k = 0; k < sizeof(valid_opcodes) / sizeof(valid_opcodes[0]); k++)
	{
		if (strcmp(valid_opcodes[k], opcode) == 0)
			return (1);
	}
	return (0);
}
/**
 * is_digit - checks for a number
 * @str: pointer
 * Return: return 1 if its an number else returns 0
 */
int is_digit(char *str)
{
	unsigned long int idx = 0;

	while (idx < strlen(str))
	{
		if (!isdigit(str[idx]) && str[idx] != '-')
			return (0);
		idx++;
	}
	return (1);
}
/**
 * free_stack - frees the stack
 * Return: Nothing
 */
void free_stack(void)
{
	free(glob_v.line);
	if (glob_v.buf != NULL)
	{
		while (glob_v.buf->prev != NULL)
		{
			glob_v.buf = glob_v.buf->prev;
			free(glob_v.buf->next);
		}
		free(glob_v.buf);
	}
	fclose(glob_v.stream);
}
