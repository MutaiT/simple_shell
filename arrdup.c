#include "tokens.h"

/**
 * arrdup - Duplicate a (NULL-terminated) array
 * @arr: The array to duplicate
 *
 * Return: A duplicate of arr
 */
char **arrdup(char **arr)
{
	char **dup = NULL;
	size_t len = 0;

	if (!arr)
		return (NULL);
	while (arr[len++])
		;
	dup = malloc(sizeof(*dup) * len);
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = _strdup(arr[len]);
	return (dup);
}
