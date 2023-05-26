#include "monty.h"

void pint_func(stack_t **stack, unsigned int line_number);

/**
 * main - Entry Point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 for success and 1 for failure.
 */

int main(int argc, char *argv[])
{
	/* Declarations */
	char buffer[100], *op_code, *operand; /*Store readline, command and values*/
	FILE *bytecodes;
	unsigned int index = 0;
	stack_t *mobile_stack = NULL;
	size_t index_two = 0;

	/* Initialisations */
	instruction_t opcode_source[] = {
		{"pall", pall_func},
		{"push", push_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{NULL, NULL}};

	/* Program Condition checks */
	if (argc < 2 || argc > 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Processes */
	bytecodes = fopen(argv[1], "r");
	if (bytecodes == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), bytecodes))
	{
		index++;
		op_code = strtok(buffer, "\n ");

		if (op_code == NULL || op_code[0] == '#')
			continue;

		index_two = 0;
		while (opcode_source[index_two].opcode != NULL)
		{
			if (strcmp(op_code, opcode_source[index_two].opcode) == 0)
			{
				if (strcmp(op_code, "push") == 0)
				{
					operand = strtok(NULL, " \n");
					if (operand == NULL || (atoi(operand) == 0 && operand[0] != '0'))
					{
						fprintf(stderr, "L%u: usage: push integer\n", index);
						exit(EXIT_FAILURE);
					}

					opcode_source[index_two].f(&mobile_stack, atoi(operand));
					break;
				}
				opcode_source[index_two].f(&mobile_stack, index);
				break;
			}
			index_two++;
		}
		if (index_two == 3)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", index, op_code);
			exit(EXIT_FAILURE);
		}
	}

	fclose(bytecodes);
	freee(mobile_stack);
	return (0);
}

/**
 * pint_func - Prints first item on stack
 * @stack: Linked list
 * @line_number:  file line number
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint_func, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
