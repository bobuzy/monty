#include "monty.h"

/**
 * pall - prints all elements in a stack
 * @list: list
 *
*/
void pall(stack_t *list)
{

	if (list == NULL)
		return;

	while (list != NULL)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}

/**
 * push - pushes an element to the stack
 * @list: list
 * @n: number to push
 *
*/
void push(stack_t *list, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = list;
	new->prev = NULL;

	if (list != NULL)
		list->prev = new;

	list = new;
}
