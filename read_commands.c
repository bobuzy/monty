#include "monty.h"

/**
 * parse_command - parses a command
 * @buff: buffer
 * @line_num: line number
 * Return: void
*/
void parse_command(char *buff, int line_num)
{
	const char *delim = "\n ";
	char *op_func, *op_arg;
	instruction_t functions[] = {
		{"push", NULL},
		{"pall", pall_func}, {"pint", pint_func},
		{"pop", pop_func}, {"swap", swap_func},
		{"nop", nop_func}, {"add", add_func},
		{"sub", sub_func}, {"div", div_func},
		{"mul", mul_func}, {"mod", mod_func},
		{"pchar", pchar_func}, {"pstr", pstr_func},
		{NULL, NULL}
	};


	op_func = strtok(buff, delim);

	if (op_func == NULL || op_func[0] == '#') /* handle comments too */
		return;


	op_arg = strtok(NULL, delim);

	find_func(op_func, op_arg, line_num, functions);
}

/**
 * read_file - reads a file and parses the commands
 * @file: file to read
*/
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
	free(buff); /* free the last buffer (if it exists) */

	fclose(fd);
}
