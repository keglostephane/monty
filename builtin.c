#include "monty.h"
/**
 * __exit - a function the free the stack before exit
 * @stack: stack
 * Return: exiting status
 */
int __exit(stack_t **stack)
{
	if (*stack)
		free_stack(*stack);
	exit(EXIT_FAILURE);
}
