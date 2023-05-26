#include "monty.h"

/**
 * swap_func - Swaps the two most items
 * @stack: linked list
 * @line_number: instruction line
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = number;
}
