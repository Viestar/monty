#include "monty.h"

/**
 * pstr - makes and prints a string from the stack.
 * @stack: list of integers
 * @line_number: Instruction index
 */

void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *local = *stack;
	int numstring;
	(void)line_number;

	for (; local; local = local->next)
	{
		numstring = local->n;
		if (numstring > 127 || numstring < 1)
			break;
		printf("%c", numstring);
	}
	printf("\n");
}
