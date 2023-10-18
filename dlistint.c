#include "monty.h"
/**
 * add_dnodeint - function that adds a new node at the beginning of
 * a stack
 * @head: pointer to dlistint
 * @n : to add in new_node
 * Return: the address of the new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exec_value = 1;
		return (NULL);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (!head || !*head)
		new_node->next = NULL;
	else
	{
		new_node->next = (*head);
		(*head)->prev = new_node;
	}
	*head =  new_node;
	return (*head);
}
/**
 * add_dnodeint_end - function that adds a new node at the beginning of
 * a stack_t
 * @head: pointer to dlistint
 * @n : to add in new_node
 * Return: the address of the new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *cursor, *prev;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exec_value = 1;
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (!head || !*head)
	{
		*head = new_node;
		new_node->prev = NULL;
		return (*head);
	}
	else
	{
		cursor = *head;
		while (cursor)
		{
			prev = cursor;
			cursor = cursor->next;
		}
		new_node->prev = prev;
		prev->next = new_node;
	}
	return (new_node);
}
/**
 * delete_dnodeint_at_index - delete node
 * @head: double linked list.
 * @index: Index.
 * Return: 1 or -1.
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp;
	unsigned int i;

	temp = *head;
	if (index == 0)
	{
		if (temp)
		{
			*head = temp->next;
			if (*head)
				(*head)->prev = NULL;
			free(temp);
			return (1);
		}
		return (-1);
	}
	for (i = 0; i < index && temp; i++)
		temp = temp->next;
	if (i == index && temp)
	{
		if (temp->next)
			(temp->next)->prev = temp->prev;
		if (temp->prev)
			(temp->prev)->next = temp->next;
		free(temp);
		return (1);
	}
	return (-1);
}
/**
 * free_stack - free dlistint
 * @head: listint
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp, *next;

	temp = head;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
