#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * @val: integer value
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, int val);
	int val;
} instruction_t;

extern int val;

void push(stack_t **stack, unsigned int line_number, int val);
void pall(stack_t **stack, unsigned int line_number, int val);
void pint(stack_t **stack, unsigned int line_number, int val);
void pop(stack_t **stack, unsigned int line_number, int val);
int validate_ops(const char *opcode);
void trim_spaces(char *str);



#endif /* MAIN_H */
