#include "monty.h"
/**
 * _stack - The opcode stack sets the format of the data to a stack (LIFO)
 * stack status value = 0 (default)
* @stack: the stack
 * @line_number: line number
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_or_queue = 0;
}
/**
 * _queue - The opcode queue sets the format of the data to a queue (FIFO).
 * queue status value = 1
* @stack: the stack
 * @line_number: line number
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_or_queue = 1;
}
