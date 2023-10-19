#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t *curr = *stack;

	len = stack_len(*stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short", line_number);
		exec_value = 1;
	}
	else
	{
		(curr->next)->n += ((curr->n);
		_pop(stack, line_number);
		exec_value = 0;
	}
}
