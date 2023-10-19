#include "monty.h"

/**
 * read_file - er input from stdin
 *
 * @filename: the given file name
 * @stack: stack
 * Return: the user input line
 */
int read_file(char *filename, stack_t **stack)
{
	char *line = NULL;
	char *opcode = NULL;
	size_t linesize = 0;
	ssize_t nread;
	int line_count = 1;
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
	while ((nread = getline(&line, &linesize, fp)) != -1)
	{
		opcode = strtok(line, DELIMITERS);

		if (opcode == NULL)
			line_count++;
		if (opcode != NULL)
		{
			get_func(opcode, stack, line_count);
			if (exec_value == 1)
			{
				free(line);
				fclose(fp);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
			line_count++;
		}


	}
	free(line);
	fclose(fp);
	return (0);
}
/**
 * get_func - a function that get the right built_in to execute
 * @opcode: first args of the line
 * @stack: stack
 * @line_count: line number
 * Return: int
 */
void get_func(char *opcode, stack_t **stack, unsigned int line_count)
{
	instruction_t fspec[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};
	int i, is_opcode = 0;

	for (i = 0; fspec[i].opcode; i++)
		if (strcmp(fspec[i].opcode, opcode) == 0)
		{
			fspec[i].f(stack, line_count);
			is_opcode = 1;
			break;
		}
	if (is_opcode == 0)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_count, opcode);
		exec_value = 1;
	}
}
