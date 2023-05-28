#include "monty.h"

/**
 * rotr - rotates the stack
 * @line_number: instruction index
 * @stack: list of integers
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *local = *stack;
	int numrot;
	(void)line_number;

	if (!local || !local->next)
		return;

	while (local->next)
		local = local->next;
	numrot = local->n;

	numrot = local->n;
	for (; local->prev; local = local->prev)
		local->n = local->prev->n;
	local->n = numrot;
}
