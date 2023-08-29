#include "monty.h"

/**
 *push - function push
 *@stack: to update the stack pointer after adding a new item.
 *@value: the value I want to add to the stack.
 *@line_number: to know which line I am in in case you need to specify
 *something or show a specific error.
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (value == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
		exit(EXIT_FAILURE);
	}

	newnode->n = value;
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}

