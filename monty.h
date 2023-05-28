#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h> /* Exit failure */
#include <unistd.h> /* Standard I/O */
#include <fcntl.h>	/* File modes */
#include <string.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct queueORstack_s - opcode and its function
 * @status: stack or queue
 * Description: status for stack or queue
 */

typedef struct queueORstack_s
{
	int status;

} queueORstack_t;

/* PROTOTYPES */
void sub_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);
void pchar_func(stack_t **stack, unsigned int line_number);
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int operand);
void freee(stack_t *head);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);

/* Global variables */
extern queueORstack_t queueORstack;

#endif /* MONTY_H */