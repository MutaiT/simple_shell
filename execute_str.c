#include "main.h"

/**
 * func_atoi - Changes string to an integer
 * @str: String to be converted
 * Return: Converted number
 */
int func_atoi(char *str)
{
	int w, x, y, z;
	unsigned int n;

	w = 0;
	x = 1;
	n = 0;
	while (str[w] != '\0')
	{
		if (str[w] == '-')
		{
			x = -x;
		}
		else if (str[w] >= '0' && str[w] <= '9')
		{
			n = n * 10 + (str[w] - '0');
			z = w + 1;
			if (str[z] < '0' || str[z] > '9')
				break;
		}
		w++;
	}
	y = n * x;
	return (y);
}

/**
 * func_itoa - Integer converter to string
 * @p: Integer
 * @s: String
 * @station: Station to use for the conversion
 * Return: String
 */
void func_itoa(int p, char *s, int station)
{
	int t = 0, x = p;

	if (x < 0)
		p = -p;
	do {
		s[t++] = p % station + '0';
	} while ((p /= station) > 0);

	if (x < 0)
		s[t++] = '-';

	s[t] = '\0';
	str_rev(s);
}

/**
 * str_rev - Function that reverses a string
 * @s: String
 */
void str_rev(char *s)
{
	int y, z;
	char c;

	for (y = 0, z = str_len(s) - 1; y < z; y++, z--)
	{
		c = s[y];
		s[y] = s[z];
		s[z] = c;
	}
}

/**
 * str_dup - duplicates a string.
 * @s: string to duplicate
 * Return: String duplicate
 */
char *str_dup(const char *s)
{
	char *str_o;
	unsigned int y, z;

	if (s == NULL)
		return (NULL);

	for (y = 0; s[y] != '\0'; y++)
		;

	str_o = (char *)malloc(sizeof(char) * (y + 1));

	if (str_o == NULL)
		return (NULL);

	for (z = 0; z <= y; z++)
		str_o[z] = s[z];

	return (str_o);
}
