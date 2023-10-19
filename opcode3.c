#include "monty.h"
/**
 * _mod - divides the second top element of the stack by the top element of the
 * stack.
 * @stack: the stack
 * @line_number: instruction line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	size_t len;

	len = stack_len(*stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exec_value = 1;
	}
	else
	{
		if ((*stack)->n == 0)
		{
			dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
			exec_value = 1;
		}
		else
		{
			(*stack)->next->n %= (*stack)->n;
			_pop(stack, line_number);
			exec_value = 0;
		}
	}
}