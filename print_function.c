#include "main.h"

/**
 * putchar_ - Function to print character in the STDOUT
 * @ch: Char to print
 * Return: Number of printed characters
 */
int putchar_(char c)
{
	static char buff[1024];
	static int y;

	if (c == -1 || y >= 1024)
	{
		write(STDOUT_FILENO, &buff, y);
		y = 0;
	}
	if (c != -1)
	{
		buff[y] = c;
		y++;
	}
	return (1);
}

/**
 * puts_ - Prototype function to print a string in STDOUT
 * @s: String
 * Return: Numbers of characters printed
 */
int puts_(char *s)
{
	register int y;

	for (y = 0; s[y] != '\0'; y++)
		putchar_(s[y]);
	putchar_(-1);
	return (y);
}
