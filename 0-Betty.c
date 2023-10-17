#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: This is the main function of the program. It
 * prints "Hello, Betty!" to the standard output.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *message = "Hello, Betty!"; /* Message to be printed */

	write(1, message, strlen(message));

	return (0);
}
