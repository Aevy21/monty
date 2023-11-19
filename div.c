#include "monty.h"

/**
 * div_f - divides the top two elements of the stack
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void div_f(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;

	pop(stack, line_number);

	if (*stack != NULL)
	{
		(*stack)->n = result;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
