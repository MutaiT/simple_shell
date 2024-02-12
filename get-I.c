#include "main.h"

/**
 * get_input - Gets users input
 *
 * Return: Returns users input.
 */
char *get_input(void)
{
	char *I = NULL;
	size_t size_input = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&I, &size_input, stdin) == -1)
	{
		free(I);
		return (NULL);
	}
	return (I);
}
