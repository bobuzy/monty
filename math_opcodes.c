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
