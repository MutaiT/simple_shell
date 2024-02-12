#include "main.h"

/**
 * path_finder - Function to find PATH value from env
 * @env_var: Enviroment variable
 * Return: PATH values
 */
char *path_finder(char **env_var)
{
	size_t total, f, element = 0;
	char *loc = NULL;

	for (f = 0; str_bytecmp(env_var[f], "PATH=", 5); f++)
		;
	if (!env_var[f])
		return (NULL);
	for (total = 5; env_var[f][element]; element++, total++)
		;
	loc = malloc(sizeof(char) * (total + 1));
	if (!loc)
		return (NULL);
	for (element = 5, total = 0; env_var[f][element]; element++, total++)
		loc[total] = env_var[f][element];
	loc[total] = '\0';

	return (loc);
}

/**
 * path_handler - Prototype function to handle the path value.
 * @token: Tokenized user command
 * @env_var: Environment variable
 * Return: Success
 */
int path_handler(char **token, char **env_var)
{
	char *v = NULL, *loc_new = NULL, *cmd = NULL;
	size_t size_path, command_size;
	struct stat st;

	if (stat(*token, &st) == 0)
		return (-1);
	v = path_finder(env_var);
	if (!v)
		return (-1);
	cmd = str_tok(v, ":");
	command_size = str_len(*token);
	while (cmd)
	{
		size_path = str_len(cmd);
		loc_new = malloc(sizeof(char) * (size_path + command_size + 2));
		if (!loc_new)
		{
			free(v);
			return (-1);
		}
		loc_new = str_cpy(loc_new, cmd);
		str_cat(loc_new, "/");
		str_cat(loc_new, *token);
		if (stat(loc_new, &st) == 0)
		{
			*token = loc_new;
			free(v);
			return (0);
		}
		free(loc_new);
		cmd = str_tok(NULL, ":");
	}
	free(v);
	return (-1);
}
