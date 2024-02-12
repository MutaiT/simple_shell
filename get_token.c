#include "main.h"

/**
 * tokenizer - Function tokenise input from the user
 * @args: User input
 * Return: String array
 */
char **tokenizer(char *args)
{
	char *t = NULL, **I = NULL;
	size_t total;
	int o = 0;

	if (!args)
		return (NULL);

	for (total = 0; args[total]; total++)
	{
		if (args[total] == ' ')
			o++;
	}
	if ((o + 1) == str_len(args))
		return (NULL);
	o += 2;
	I = malloc(sizeof(char *) * (o));
	if (!I)
		return (NULL);

	t = str_t(args, " \n\t\r");
	for (total = 0; t != NULL; total++)
	{
		I[total] = t;
		t = str_t(NULL, " \n\t\r");
	}
	I[total] = NULL;
	return (I);
}

/**
 * delimeter_check - Finds delimeter characters
 * @ch: Char
 * @s: The string
 * Return: 0 if successful
 */
unsigned int delimeter_check(char ch, const char *s)
{
	unsigned int total;

	for (total = 0; s[total] != '\0'; total++)
	{
		if (ch == s[total])
			return (1);
	}
	return (0);
}

/**
 * str_tok - Tokenises a string
 * @s: String
 * @mark: String delimeter
 * Return: A tokenized string
 */
char *str_tok(char *s, const char *mark)
{
	static char *t, *n_t;
	unsigned int y;

	if (s != NULL)
		n_t = s;
	t = n_t;
	if (t == NULL)
		return (NULL);
	for (y = 0; t[y] != '\0'; y++)
	{
		if (delimeter_check(t[y], mark) == 0)
			break;
	}
	if (n_t[y] == '\0' || n_t[y] == '#')
	{
		n_t = NULL;
		return (NULL);
	}
	t = n_t + y;
	n_t = t;
	for (y = 0; n_t[y] != '\0'; y++)
	{
		if (delimeter_check(n_t[y], mark) == 1)
			break;
	}
	if (n_t[y] == '\0')
		n_t = NULL;
	else
	{
		n_t[y] = '\0';
		n_t = n_t + y + 1;
		if (*n_t == '\0')
			n_t = NULL;
	}
	return (t);
}
