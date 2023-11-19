#include "monty.h"

/**
 * check_spaces - removes whitespaces
 * Return: Always 0 success
 */
int check_spaces(void)
{
	char *str = glob_v.line;
	unsigned int len = strlen(str);
	unsigned int idx = 0;

	if (str[0] == '#')
	{
		return (1);
	}
	while (idx < len - 1)
	{
		if (str[idx] != ' ')
		{
			return (0);
		}
		idx = idx + 1;
	}
	return (1);
}

/**
 * validate_ops - validates opcodes
 * @opcode: pointer to an opcode
 * Return: Always 0 Success
 */
int validate_ops(const char *opcode)
{
	size_t k;
	char *valid_ops[] = {"push", "pall", "pint", "pop", "add", "swap", "nop"};

	if (opcode == NULL || opcode[0] == '\0')
		return (1);

	for (k = 0; k < sizeof(valid_ops) / sizeof(valid_ops[0]); k++)
	{
		if (strcmp(valid_ops[k], opcode) == 0)
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
	stack_t *temp;

	if (glob_v.line)
	{
		free(glob_v.line);
		glob_v.line = NULL;
	}
	temp = glob_v.buf;
	while (temp)
	{
		glob_v.buf = temp->next;
		free(temp);
		temp = glob_v.buf;
	}
	if (glob_v.stream != NULL)
	{
		fclose(glob_v.stream);
		glob_v.stream = NULL;
	}
}
