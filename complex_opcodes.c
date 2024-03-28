#include "monty.h"

/**
 * pchar_func - prints the char at the top of the stack
 * @list: list
 * @line_num: line number
 *
 */
void pchar_func(stack_t **list, unsigned int line_num)
{
	if (!list || !(*list))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*list)->n < 0 || (*list)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*list)->n);
}

/**
 * pstr_func - prints the string starting at the top of the stack
 * @list: list
 * @line_num: line number
 *
 */
void pstr_func(stack_t **list, unsigned int line_num)
{
	stack_t *ptr = *list;

	(void)line_num;

	while (ptr && ptr->n > 0 && ptr->n <= 127)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");
}
