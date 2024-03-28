#ifndef HEADER
#define HEADER

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *h;
typedef void (*opcode_func)(stack_t **stack, unsigned int num);

/* opcodes' functions */
void push_func(stack_t **list, int value, unsigned int line_num);
void pall_func(stack_t **list, unsigned int line_num);
void pint_func(stack_t **list, unsigned int line_num);

/* main functions */
void read_file(char *file);
void parse_command(char *buff, int num);
void find_func(char *op_func, char *op_arg, int line_num);

/* helper functions */
void free_stack(stack_t *head);

#endif
