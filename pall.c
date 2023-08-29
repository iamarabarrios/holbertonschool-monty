#include "monty.h"

/**
 *pall - print
 *@stack: to update the stack pointer after adding a new item.
 *@line_number: to know which line I am in in case you need to specify
 *something or show a specific error.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)(line_number);

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;

		if (head == *stack)
			return;
	}
}
