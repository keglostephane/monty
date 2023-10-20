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

/**
 * _pchar - prints the char at the top of the stack
 *
 * @stack: the stack
 * @line_number: instruction line number
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack != NULL)
		num = (*stack)->n;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		exec_value = 1;
	}
	else if (isascii(num) == 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, value out of range\n", line_number);
		exec_value =  1;
	}
	else
	{
		printf("%c\n", num);
		exec_value = 0;
	}
}

/**
 * _pstr - prints the string at the top of the stack
 *
 * @stack: the stack
 * @line_number: instruction line number
 *
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void)line_number;

	for (top = *stack; top && top->n && isascii(top->n); top = top->next)
		putchar(top->n);

	printf("\n");
}
/**
 * _rotl - op element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @stack: the stack
 * @line_number: line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top)
	{
		add_dnodeint_end(stack, top->n);
		_pop(stack, line_number);
	}
}
