#include "monty.h"
/**
 * _push - a function that pushes an element to the stack
 * @stack: stack_t
 * @line_number: line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int data, is_number = 2;
	char *str_int = NULL;

	str_int = strtok(NULL, DELIMITERS);
	if (str_int != NULL)
		is_number = _isnumber(str_int);
	if (is_number != 1 || !str_int)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exec_value = 1;
	}
	else
	{
		data = atoi(str_int);
		add_dnodeint(stack, data);
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
