#include "monty.h"

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
