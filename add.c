#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
