#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @list: list
 * @value: value to push
 * @line_num: line number
 *
*/
void push_func(stack_t **list, int value, unsigned int line_num)
{
	stack_t *new = malloc(sizeof(stack_t));
	(void)line_num;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->next = *list;
	new->prev = NULL;

	if (*list != NULL)
	{
		(*list)->prev = new;
	}

	*list = new;
}

/**
 * pall_func - prints all the values on the stack
 * @list: list
 * @line_num: line number
 *
*/
void pall_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	(void)line_num;

	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	ptr = *list;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
