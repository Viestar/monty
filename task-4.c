#include "monty.h"

/**
 * add_func - Adds two top most
 * @stack: linked list
 * @line_number: instruction line number
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_func(stack, line_number);
}
