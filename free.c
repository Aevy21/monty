#include "monty.h"

/**
 * free_stack - frees the stack and other allocated memory
 * Return: Nothing
 */
void free_stack(void)
{
	free(glob_v.line);  /* Free dynamically allocated line*/
	glob_v.line = NULL;
	/* Set the pointer to NULL after freeing*/

	/* Free the linked list*/
	while (glob_v.buf != NULL)
	{
		stack_t *temp = glob_v.buf;
		glob_v.buf = glob_v.buf->prev;
		free(temp);
	}

	fclose(glob_v.stream);  /* Close the file stream */
}

