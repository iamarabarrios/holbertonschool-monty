#include "monty.h"
#include <stdio.h>

/**
 * check_for_digit - check that it only has digits
 * @arg: string for check
 * Return: 0 if they are just digits, and if not 1
 */
int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if ((arg[i] == '-' && i == 0) || !isdigit(arg[i]))
			return (1);
	}
	return (0);
}

/**
 *push - function push
 *@stack: to update the stack pointer after adding a new item.
 *@line_number: to know which line I am in in case you need to specify
 *something or show a specific error.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;

	arg = strtok(NULL, "\n\t\r ");

	int n = atoi(arg);

	if (arg == NULL || check_for_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!add_node(stack, n))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
