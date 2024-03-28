#include "monty.h"
stack_t *h = NULL;

/**
 * main - entry point
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: 0 on success
*/
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1]);
	free_stack(h);
	return (0);
}

/**
 * find_func - finds the function to execute
 * @op_func: opcode
 * @op_arg: argument
 * @line_num: line number
 * @functions: array of functions of opcodes
 *
*/
void find_func(char *op_func, char *op_arg, int line_num,
				instruction_t *functions)
{
	int n, value;
	size_t i;

	for (n = 0; functions[n].opcode != NULL; n++)
	{
		if (strcmp(op_func, functions[n].opcode) == 0)
		{
			if (n == 0)
			{
				if (op_arg == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
				}
				for (i = 0; i < strlen(op_arg); i++)
				{
					if (!isdigit(op_arg[i]))
					{
						fprintf(stderr, "L%d: invalid value for push\n", line_num);
						exit(EXIT_FAILURE);
					}
				}
				value = atoi(op_arg);
				push_func(&h, value, line_num);
			}
			else
				functions[n].f(&h, line_num);

			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_func);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - function that frees a dlistint_t list
 *
 * @head: pointer to head
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
