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
	int temp;
	size_t len;

	len = stack_len(*stack);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exec_value = 1;
	}
	else
	{
		temp  = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
		exec_value = 0;
	}
}

/**
 * _sub - substracts the top element of the stack from the second top element
 *
 * @stack: the stack
 * @line_number: instruction line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	size_t len;

	len = stack_len(*stack);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exec_value = 1;
	}
	else
	{
		(*stack)->next->n -= (*stack)->n;
		_pop(stack, line_number);
		exec_value = 0;
	}
}
/**
 * _div - divides the second top element of the stack by the top element of the
 * stack.
 * @stack: the stack
 * @line_number: instruction line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	size_t len;

	len = stack_len(*stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
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
			(*stack)->next->n /= (*stack)->n;
			_pop(stack, line_number);
			exec_value = 0;
		}
	}
}
/**
 * _mul - multiply the top two elements of the stack.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t *curr = *stack;

	len = stack_len(*stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exec_value = 1;
	}
	else
	{
		(curr->next)->n *= curr->n;
		_pop(stack, line_number);
		exec_value = 0;
	}
}
