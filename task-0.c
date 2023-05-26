#include "monty.h"

/**
 * push_func - Addes an item to the stack
 * @stack: stack to be appended
 * @operand: data to be added
 */

void push_func(stack_t **stack, unsigned int operand)
{
	stack_t *temp_stack;

	/* Allocate memory for the temporary stack */
	temp_stack = malloc(sizeof(stack_t));
	if (!temp_stack)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp_stack->prev = NULL;
	temp_stack->n = operand;
	temp_stack->next = NULL;

	if (*stack)
	{
		(*stack)->prev = temp_stack;
		temp_stack->next = *stack;
		*stack = temp_stack;
	}
	else
		*stack = temp_stack;
}

/**
 * pall_func - prints details of the stack
 * @stack: Stack
 * @operand: value
 */
void pall_func(stack_t **stack, unsigned int operand)
{
	stack_t *temp_stack;

	temp_stack = *stack;
	(void)operand;

	while (temp_stack)
	{
		printf("%d\n", temp_stack->n);
		temp_stack = temp_stack->next;
	}
}
