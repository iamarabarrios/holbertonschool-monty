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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
		line_number++;
		buffer[strcspn(buffer, "\n")] = '\0';
		if (sscanf(buffer, "%s %d", opcode, &value) == 2)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&top, value, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&top, line_number);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fprintf(stderr, "USAGE: monty file\n");
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

