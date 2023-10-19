#include "monty.h"
/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 * Return: 0 always success
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	exec_value = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);

	free_stack(stack);
	exit(EXIT_SUCCESS);
}
