#include "monty.h"

/**
 *push - function push
 *@stack: to update the stack pointer after adding a new item.
 *@value_str: the value I want to add to the stack.
 *@line_number: to know which line I am in in case you need to specify
 *something or show a specific error.
 */

void push(stack_t **stack, char *value_str, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	char *endptr;
	long value = strtol(value_str, &endptr, 10);
	int int_value = (int)value;

	if (*endptr != '\0' && !isspace((unsigned char)*endptr))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = int_value;
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}

