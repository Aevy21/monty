#include "monty.h"

/**
 * push - pushs a node onto a stack
 * @stack: pointer to a stack
 * @line_number: an integer
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
	(void)line_number;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}

	new_node->n = glob_v.val;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		new_node->prev = NULL;
		*stack = new_node;
	}
	glob_v.buf = *stack;
}
