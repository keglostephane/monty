#include "monty.h"
/**
 * _push - a function that pushes an element to the stack
 * @stack: stack_t
 * @line_number: line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int data;
	long num;
	char *str, *end;

	str = strtok(NULL, DELIMITERS);

	if (str != NULL)
		num = strtol(str, &end, 10);
	if (str == NULL || str == end)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exec_value = 1;
	}
	else
	{
		data = (int)(num);
		if (add_dnodeint(stack, data) != NULL)
			exec_value = 0;
	}
}
/**
 * _pall - a function that print all elements in the stack starting from top
 * @stack: stack_t
 * @line_number: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cursor;

	(void)line_number;
	cursor = *stack;
	while (cursor)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}
/**
 * _pint - a function that print the first element of the stack
 * @stack: stack_t
 * @line_number: line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exec_value = 1;
	}
	else
	{
		printf("%d\n", (*stack)->n);
		exec_value = 0;
	}
}

/**
 * _pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: instruction line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exec_value = 1;
	}
	else
	{
		delete_dnodeint_at_index(stack, 0);
		exec_value = 0;
	}
}
/**
 * _nop - a function that do anything on call
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
