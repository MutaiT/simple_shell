#include "ctype.h"

/**
  * _isalnum - Checks if the character is alphanumeric
  * @c: Character to check
 * Return: If c is alphanumeric, return 1. Otherwise, return 0.
  */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
