#include "main.h"

/**
 * str_cmp - Function to compare two strings
 * @str1: String one
 * @str2: String two
 *
 * Return: Differential
 */
int str_cmp(char *str1, char *str2)
{
	int cmp, c;

	c = 0;
	while (str1[c] != '\0' && str2[c] != '\0')
	{
		cmp = str1[c] - str2[c];
		if (cmp)
			return (cmp);
		c++;
	}
	cmp = str1[c] - str2[c];
	if (cmp)
		return (cmp);

	return (0);
}

/**
 * str_len - Function to get string length
 * @s: String
 * Return: Length
 */
int str_len(char *s)
{
	int l = 0;

	while (s[l])
		l++;

	return (l);
}

/**
 * str_bytecmp - Function to compare first n bytes of two strings
 * @str1: String one
 * @str2: String two
 * @nmbr: Bytes to compare
 * Return: 0, diffrence on failure
 */
size_t str_bytecmp(char *str1, char *str2, size_t nmbr)
{
	size_t c, Asc;

	for (c = 0; str1[c] != '\0' && c < nmbr; c++)
	{
		Asc = str1[c] - str2[c];

		if (Asc != 0)
			return (Asc);
	}
	return (0);
}

/**
 * str_cat - Prototype function to concatenate two strings
 * @to: Destination of the string
 * @from: Source of the string
 *
 * Return: Concatenated string
 */
char *str_cat(char *to, char *from)
{
	int w = 0, x = 0;

	while (to[w])
		w++;

	while (from[x])
	{
		to[w] = from[x];
		w++;
		x++;
	}
	to[w] = '\0';
	return (to);
}

/**
 * str_cpy - Function to copy string content
 * @to: Copy to
 * @from: Copy from
 *
 * Return: Copied string
 */
char *str_cpy(char *to, char *from)
{
	int y = 0;

	while (from[y])
	{
		to[y] =from[y];
		y++;
	}
	to[y] = from[y];

	return (to);
}
