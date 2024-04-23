#include "quote.h"

/**
 * _quote_state_none - Get state length and next state
 * @str: String
 * @state: State
 *
 * Return: Length of state
 */
size_t _quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (isspace(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * _quote_state_word - Get state length and next state
 * @str: String
 * @state: State
 *
 * Return: Length of state
 */
size_t _quote_state_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !isspace(*str) && !isquote(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * _quote_state_double - Get state length and next state
 * @str: String
 * @state: State
 *
 * Return: Length of state
 */
size_t _quote_state_double(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '"')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 * _quote_state_single - Get state length and next state
 * @str: String
 * @state: State
 *
 * Return: Length of state
 */
size_t _quote_state_single(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '\'')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 * _quote_state_escape - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}
