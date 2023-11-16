#include "monty.h"

/**
 * pint - prints out the top element to stdout
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", top->n);
	}
}
