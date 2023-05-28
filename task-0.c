#include "monty.h"

/**
 * push_func - Addes an item to the stack
 * @stack: stack to be appended
 * @operand: data to be added
 */

void push_func(stack_t **stack, unsigned int operand)
{
	stack_t *temp_stack, *new;

	new = *stack;

	/* Allocate memory for the temporary stack */
	temp_stack = malloc(sizeof(stack_t));
	if (!temp_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp_stack->prev = NULL;
	temp_stack->n = operand;
	temp_stack->next = NULL;

	if (*stack)
	{
		if (queueORstack.status == 200)
		{
			(*stack)->prev = temp_stack;
			temp_stack->next = *stack;
			*stack = temp_stack;
		}
		else if (queueORstack.status == 100)
		{
			while (new->next != NULL)
				new = new->next;
			new->next = temp_stack;
			temp_stack->prev = new;
		}
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
