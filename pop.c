#include "monty.h"

/**
 * pop - pops a node from a stack
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;

}
