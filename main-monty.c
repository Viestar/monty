#include "monty.h"

/**
 * main - Entry Point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 for success and 1 for failure.
 */

int main(int argc, char *argv[])
{

	/* Initialisations */
	instruction_t opcode_source[] = {
		{"pall", pall_func}, {"push", push_func}, {NULL, NULL}};

	/* Program Condition checks */
	if (argc < 2 || argc > 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monky_interpreter(argv, opcode_source);

	return (0);
}

