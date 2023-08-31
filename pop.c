#include "monty.h"

/**
 * pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;

	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
		*stack = temp->next;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
	var.stack_len--;
}
