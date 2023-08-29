#include "monty.h"
/**
 *free_lineptr - free_lineptr
 *@status: int
 *@arg: pointer
 */
void free_lineptr(int status __attribute__((unused)), void *arg)
{
	char **lineptr = arg;

	if (*lineptr != NULL)
	{
		free(*lineptr);
		*lineptr = NULL;
	}
}

/*
 * free_stack - Free stack
 * @status: int
 * @arg: Pointer
 */
void free_stack(int status __attribute__((unused)), void *arg)
{
	stack_t **stack = (stack_t **)arg;

	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

/*
 * fs_close - fclose
 * @status: int
 * @arg: Pointer
 * Return: void
 */
void fs_close(int status __attribute__((unused)), void *arg)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) arg;
	fclose(fs);
}
