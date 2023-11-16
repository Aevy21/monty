#include "monty.h"

/**
 * swap - swaps the first two elements of the stack
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	/* check if stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* swap the top two elements of the stack */
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}