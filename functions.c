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
 * is_digit - checks if a str is a digit or not
 * @str: pointer to a string
 * Return: 1 if its a digit 0 if not
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (!isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
