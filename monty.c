#include "monty.h"
stack_t *h = NULL;

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1]);
	return (0);
}

void read_file(char *file)
{
	int line_num = 1;
	char *buff = NULL;
	size_t buff_len = 0;

	FILE *fd = fopen(file, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &buff_len, fd) != -1)
	{
		if (buff == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		parse_command(buff, line_num);
		free(buff);
		buff = NULL;
		buff_len = 0;
		line_num++;
	}

	fclose(fd);
}

void parse_command(char *buff, int line_num)
{
	const char *delim = "\n ";
	char *op_func, *op_arg;

	op_func = strtok(buff, delim);

	if (op_func == NULL)
	{
		return;
	}

	op_arg = strtok(NULL, delim);

	find_func(op_func, op_arg, line_num);
}

void find_func(char *op_func, char *op_arg, int line_num)
{
	int n;

	instruction_t functions[] = {
		{"push", NULL},
		{"pall", pall_func},
		{NULL, NULL}
	};

	for (n = 0; functions[n].opcode != NULL; n++)
	{
		if (strcmp(op_func, functions[n].opcode) == 0)
		{
			if (n == 0 && op_arg != NULL)
			{
				int value = atoi(op_arg);

				push_func(&h, value, line_num);
			}
			else
			{
				functions[n].f(&h, line_num);
			}
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_func);
	exit(EXIT_FAILURE);
}

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
