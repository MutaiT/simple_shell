#include "ctype.h"

/**
  * _isalpha - Checks if the character is alphabetic
  * @c: Character to check
 * Return: If c is alphabetic, return 1. Otherwise, return 0.
  */
bool _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
