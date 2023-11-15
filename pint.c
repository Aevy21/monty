#include "monty.h"

/**
 * pint - prints out the top element to stdout
 * @stack: pointer to a stack
 * @line_number: an integer
 * @val: an integer
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number, int val)
{
	stack_t *top = *stack;
	(void)val;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	}
	else
	{
		printf("%d\n", top->n);
	}
}
