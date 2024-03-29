#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @list: list
 * @line_num: line number
 *
 */
void add_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	if (!list || !(*list) || (*list)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*list)->next;
	ptr->n += (*list)->n;

	pop_func(list, line_num);
}

/**
 * sub_func - subtracts the top element of the stack
 *			from the second top element
 * @list: list
 * @line_num: line number
 *
 */
void sub_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	if (!list || !(*list) || (*list)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*list)->next;
	ptr->n -= (*list)->n;

	pop_func(list, line_num);
}

/**
 * div_func - divides the second top element of the stack
 *				by the top element of the stack.
 * @list: list
 * @line_num: line number
 *
 */
void div_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	if (!list || !(*list) || (*list)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*list)->next;
	if ((*list)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	ptr->n /= (*list)->n;

	pop_func(list, line_num);
}

/**
 * mul_func - multiplies the second top element of the stack
 *				with the top element of the stack.
 * @list: list
 * @line_num: line number
 *
 */
void mul_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	if (!list || !(*list) || (*list)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*list)->next;
	ptr->n *= (*list)->n;

	pop_func(list, line_num);
}

/**
 * mod_func - computes the rest of the division of the second
 *				top element of the stack by the top element of the stack.
 * @list: list
 * @line_num: line number
 *
 */
void mod_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	if (!list || !(*list) || (*list)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*list)->next;
	if ((*list)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	ptr->n %= (*list)->n;

	pop_func(list, line_num);
}
