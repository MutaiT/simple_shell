#include "builtins.h"

/**
 * __alias_add - Adds an alias to a list of aliases
 * @aliases: A pointer to a list of aliases
 * @name: The name of the alias
 * @value: The value of the alias
 */
void __alias_add(alias_t **aliases, const char *name, const char *value)
{
	alias_t *alias = get_dict_node(aliases ? *aliases : NULL, name);

	if (alias)
	{
		free(alias->val);
		alias->val = _strdup(value);
	}
	else
	{
		add_dict_node_end(aliases, name, value);
	}
}


/**
 * __alias_print - Prints an alias
 * @alias: The alias to be printed
 */
void __alias_print(alias_t *alias)
{
	write(STDOUT_FILENO, alias->key, _strlen(alias->key));
	write(STDOUT_FILENO, "='", 2);
	write(STDOUT_FILENO, alias->val, _strlen(alias->val));
	write(STDOUT_FILENO, "'\n", 2);
}


/**
 * __alias - Creates and displays aliases
 * @info: Shell info struct
 *
 * Return: Status
 */
int __alias(info_t *info)
{
	alias_t *alias;
	char *name, **args = info->tokens + 1;
	ssize_t name_len;

	info->status = EXIT_SUCCESS;
	if (*args)
	{
		do {
			name_len = _strchr(*args, '=');
			if (name_len == -1)
			{
				alias = get_dict_node(info->aliases, *args);
				if (alias)
				{
					__alias_print(alias);
				}
				else
				{
					perrorl("not found", *info->tokens, *args, NULL);
					info->status = EXIT_FAILURE;
				}
			}
			else
			{
				name = _strndup(*args, name_len);
				__alias_add(&info->aliases, name, *args + name_len + 1);
				free(name);
			}
		} while (*++args);
	}
	else
	{
		for (alias = info->aliases; alias; alias = alias->next)
			__alias_print(alias);
	}
	return (info->status);
}
