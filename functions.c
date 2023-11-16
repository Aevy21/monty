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
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *ptr;

	ptr = head;
	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
