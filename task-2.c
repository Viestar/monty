#include "monty.h"

/**
 * pop_func - Removes the topmost element of the stack
 * @stack: linked list
 * @line_number: instruction line number
 */

void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *mobile_stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	mobile_stack = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(mobile_stack);
}
