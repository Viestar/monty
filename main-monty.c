#include "monty.h"


/**
 * main - Entry Point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 for success and 1 for failure.
 */

int main(int argc, char *argv[])
{
	/* Declarations */
	FILE *bytecodes;

	/* Initialisations */
	instruction_t opcode_source[] = {
		{"pall", pall_func}, {"push", push_func}, {NULL, NULL}};

	/* Program Condition checks */
	if (argc < 2 || argc > 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Processes*/
	bytecodes = fopen(argv[1], O_RDONLY);
	if (bytecodes != NULL)
		monky_interpreter(bytecodes, opcode_source);
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
