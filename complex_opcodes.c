#include "monty.h"

/**
 * pchar_func - prints the char at the top of the stack
 * @list: list
 * @line_num: line number
 *
 */
void pchar_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	if (!list || !(*list))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = *list;

	if (ptr->n < 0 || ptr->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_stack(ptr);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ptr->n);
	free_stack(ptr);
}

/**
 * pstr_func - prints the string starting at the top of the stack
 * @list: list
 * @line_num: line number
 *
 */
void pstr_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr;

	(void)line_num;

	if (!list || !(*list))
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	ptr = *list;

	while (ptr != NULL)
	{
		if (ptr->n < 0 || ptr->n > 127 || ptr->n == 0)
		{
			printf("\n");
			free_stack(ptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("%c", ptr->n);
			ptr = ptr->next;
		}
	}
	printf("\n");
	free_stack(ptr);
}
