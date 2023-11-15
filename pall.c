#include "monty.h"

/**
 * pall - prints out all the elements in a stack to stdout
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if (ptr == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}
