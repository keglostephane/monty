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
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exec_value = 1;
	}
	else
	{
		(curr->next)->n += curr->n;
		_pop(stack, line_number);
		exec_value = 0;
	}
}

/**
 * _swap - swap the top two elements of the stack
 *
 * @stack: the stack
 *
 * @line_number: instruction line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int a, b;
	size_t len;

	len = stack_len(*stack);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exec_value = 1;
	}
	else
	{
		a = (*stack)->n;
		delete_dnodeint_at_index(stack, 0);
		b = (*stack)->n;
		delete_dnodeint_at_index(stack, 0);

		if (add_dnodeint(stack, a) == NULL)
			return;
		if (add_dnodeint(stack, b) == NULL)
			return;
	}
}
