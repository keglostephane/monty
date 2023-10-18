#include "monty.h"
/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 * Return: 0 always success
 */
int main(int argc, char **argv)
{
	int check;
	stack_t *stack;

	exec_value = 0;
	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		__exit(&stack);
	}
	check = read_file(argv[1], &stack);
	if (check == 0)
		free_stack(stack);
	return (exec_value);
}
