#include "monty.h"

/**
 * monky_interpreter - intepretes and executes opcodes
 * @bytecodes: file of instructions
 * @opcode_source: struct for functions.
 */

void monky_interpreter(char *bytecodes, instruction_t *opcode_source)
{
	char *buffer, *op_code; /* Store readline and command */
	int line_len, index;
	ssize_t read_line;	  /* return on line reading */
	unsigned int operand; /* Stores value */
	stack_t *mobile_stack = NULL;

	while ((read_line = getline(&buffer, &line_len, bytecodes)) != -1)
	{
		index++;
		op_code = strtok(buffer, " ");
		operand = strtok(NULL, " ");
		if (op_code == "push")
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
				opcode_source[index].f(&mobile_stack, operand);
			else
			{
				dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", operand, op_code);
				exit(EXIT_FAILURE);
			}
		}
	}
}