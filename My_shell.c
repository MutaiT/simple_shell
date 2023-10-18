#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - A program for a simple shell
 *
 * Return: 0 SUCCESS
 */
int main(void)
{
	char insert[MAX_INPUT_SIZE];

	while (1)
	{
		/* Display the prompt and wait for user input */
		printf("simple_shell> ");

		if (fgets(insert, MAX_INPUT_SIZE, stdin) == NULL)
		{
			/* Handle "end of file" (Ctrl+D) */
			/* printf("\n"); */
			break;
		}

		/* Remove the newline character */
		size_t insert_length = strlen(insert);

		if (insert_length > 0 && insert[insert_length - 1] == '\n')
		{
			insert[insert_length - 1] = '\0';
		}

		/* Use the input as the command to execute */
		int result = system(insert);

		if (result == -1)
		{
			/* Handle the case when the executable is not found */
			printf("Command not found: %s\n", insert);
		}
	}

	return (0);
}
