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

/**
 * pint_func - prints the value at the top of the stack
 * @list: list
 * @line_num: line number
 *
*/
void pint_func(stack_t **list, unsigned int line_num)
{
	if (!list || !(*list))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*list)->n);
}

/**
 * pop_func - removes the top element of the stack
 * @list: list
 * @line_num: line number
 *
*/
void pop_func(stack_t **list, unsigned int line_num)
{
	stack_t *tmp;

	if (!list || !(*list))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}

/**
 * swap_func - swaps the top two elements of the stack
 * @list: list
 * @line_num: line number
 *
*/
void swap_func(stack_t **list, unsigned int line_num)
{
	stack_t *tmp;

	if (!list || !(*list) || !(*list)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*list)->next;
	(*list)->next = tmp->next;

	if (tmp->next)
	{
		tmp->next->prev = *list;
	}

	tmp->prev = NULL;
	tmp->next = *list;
	(*list)->prev = tmp;
	*list = tmp;
}
