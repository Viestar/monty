#include "monty.h"

/**
 * freee - Frees a tack
 * @head: pointer to the haed
 */
void freee(stack_t *head)
{
	stack_t *local;

	while (head != NULL)
	{
		local = head->next;
		free(local);
		head = local;
	}
}
