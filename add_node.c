#include "monty.h"
/**
 *add_node - add node
 *@stack: stack_t
 *@n: int
 *Return: new_node
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

