#include "monty.h"
stack_t *top = NULL;

int
main(int argc, char *argv[])
{
	char buffer[1024];
	char opcode[10];
	int value;
	unsigned int line_number = 0;
	FILE *file;
	stack_t *temp = top;

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s %s %s\n", argv[0], argv[1], argv[2]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		if (sscanf(buffer, "%s %d", opcode, &value) == 2)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&top, value, 0);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&top, 0);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				return (EXIT_FAILURE);
			}
		}
	}
	fclose(file);

	while (top != NULL)
	{
		top = top->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}

