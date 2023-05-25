#include "monty.h"

void freee(stack_t *head);

/**
 * monky_interpreter - intepretes and executes opcodes
 * @argv: file of instructions
 * @opcode_source: struct for functions.
 */

void monky_interpreter(char **argv, instruction_t *opcode_source)
{
	FILE *bytecodes;
	char buffer[1024], *op_code, *operand; /*Store readline, command and values*/
	unsigned int index;
	stack_t *mobile_stack = NULL;

	bytecodes = fopen(argv[1], O_RDONLY);
	if (bytecodes != NULL)
	{
		while (fgets(buffer, sizeof(buffer), bytecodes))
		{
			index++;
			op_code = strtok(buffer, " ");
			operand = strtok(NULL, " ");
			if (atoi(op_code) == atoi("push"))
			{
				if (operand == NULL || atoi(operand) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer", index);
					exit(EXIT_FAILURE);
				}
			}
			while (opcode_source)
			{
				if (strcmp(op_code, opcode_source[index].opcode) == 0)
					opcode_source[index].f(&mobile_stack, atoi(operand));
				else
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", index, op_code);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fclose(bytecodes);
	freee(mobile_stack);
}

/**
 * freee - Frees a tack
 * @head: pointer to the haed
 */
void freee(stack_t *head)
{
	stack_t *local = head;

	while (head)
	{
		head = (*head).next;
		free(local);
		local = head;
	}
}
