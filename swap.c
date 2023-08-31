#include "monty.h"

/**
 * swap - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		fprintf(stderr,	"L%u: can't swap, stack too short\n",	line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		next = (*stack)->next;
		(*stack)->next = next->next;
		next->next = *stack;
		next->prev = NULL;
		(*stack)->prev = next;
		*stack = next;
	}
	else
	{
		next = (*stack)->next;
		(*stack)->next = next->next;
		next->next->prev = *stack;
		next->next = (*stack);
		(*stack)->prev = next;
		(*stack) = next;
	}
}
