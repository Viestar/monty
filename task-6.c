#include "monty.h"

/**
 * sub_func - subtracts two top most elements.
 * @stack: linked list
 * @line_number: instruction line number
 */

void sub_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop_func(stack, line_number);
}
