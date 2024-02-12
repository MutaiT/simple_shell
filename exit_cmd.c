#include "main.h"

/**
 * exit_cmd - Function prototype to exit
 * @token: Tokenized command
 * @line: User's input
 * @done: The exit status
 */
void exit_cmd(char **token, char *line, int done)
{
	int progression = 0;

	if (!token[1])
	{
		free(line);
		free(token);
		exit(done);
	}
	progression = func_atoi(token[1]);
	free(line);
	free(token);
	exit(progression);
}

/**
 * env_check - Checks inbuilt enviroment variables
 * @env_var: Enviroment variable
 */
void env_check(char **env_var)
{
	size_t o = 0;

	while (env_var[o])
	{
		write(STDOUT_FILENO, env_var[o], str_len(env_var[o]));
		write(STDOUT_FILENO, "\n", 1);
		o++;
	}
}
