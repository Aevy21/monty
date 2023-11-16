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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var - variables -args, stream, line content
 * @stream: pointer to file
 * @line: line content
 * @val: int value;
 * @buf: pointer to a buffer
 * @ptr: pointer to printed values
 * Description: carries values through the program
 */
typedef struct global_var
{
	FILE *stream;
	char *line;
	stack_t *buf;
	stack_t *ptr;
	int val;
}  stack_var;

extern stack_var glob_v;

stack_var glob_v;


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
int validate_ops(const char *opcode);
void trim_spaces(char *str);
int is_digit(char *str);
void free_stack(void);
void execute(char *op, char *arg, unsigned int line_number);


#endif /* MAIN_H */
