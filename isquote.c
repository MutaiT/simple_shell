#include "ctype.h"

/**
 * _isquote - Check if a character is a quote
 * @c: The character to check
 * Return: If c is a quote, return 1. Otherwise, return 0.
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
