#include "ctype.h"

/**
  * _isident - Checks if the character is a valid identifier character
  * @c: Character to check
 * Return: If c is an identifier character, return 1. Otherwise, return 0.
  */
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}
