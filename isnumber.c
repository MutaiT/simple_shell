#include "ctype.h"

/**
  * _isnumber - Check if a string consists only of digits
  * @s: Pointer to string
  * Return: True or False
  */
bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
