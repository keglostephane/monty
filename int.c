#include "monty.h"
/**
 * _isnumber - check is an input is a number or not
 *
 * @c: string to check
 *
 * Return: 1 if `c` is a number, 0 otherwise
 *
 */
int _isnumber(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
		if (c[i] < 48 || c[i] > 57)
			return (0);
	return (1);
}
