#include "monty.h"

/**
 *pall - print
 *@stack: to update the stack pointer after adding a new item.
 *@line_number: to know which line I am in in case you need to specify
 *something or show a specific error.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	line_number = line_number;

	if (*stack == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
