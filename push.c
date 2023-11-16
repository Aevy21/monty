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
		exit(EXIT_FAILURE);
	}

	new_node->n = glob_v.val;
	new_node->prev = NULL;
	new_node->next = *stack;

	*stack = new_node;
}
