#include "monty.h"

/**
 * rotl - rotates the stack
 * @line_number: instruction index
 * @stack: list of integers
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *local = *stack;
	int numrot;
	(void)line_number;

	if (!local || !local->next)
		return;

	numrot = local->n;
	for (; local->next; local = local->next)
		local->n = local->next->n;
	local->n = numrot;
}
