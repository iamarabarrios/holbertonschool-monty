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

	if (var.stack_len == 0)
	{
		fprintf(stdout, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len != 1)
	*stack = NULL;

	else
	{
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->prev->next = (*stack)->next;
		*stack = (*stack)->next;
	}
	var.stack_len--;
}
