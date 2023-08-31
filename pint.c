#include "monty.h"

/**
 * pint - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		fprintf(stdout, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
