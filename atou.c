#include "builtins.h"

/**
 * atou - Converts a string to an integer
 * @s: Character to check
 * Return: int
 */
unsigned int atou(char *s)
{
	size_t x;
	unsigned int number = 0;
	unsigned int to_add;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (UINT_MAX / 10 < number)
			return (UINT_MAX);
		number *= 10;
		to_add = s[x] - '0';
		if (UINT_MAX - to_add < number)
			return (UINT_MAX);
		number += to_add;

	}
	return (number);
}
