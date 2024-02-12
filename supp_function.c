#include "main.h"

/**
 * support_func - Prototype functions handling commands not in path
 * @input: Commands tokenised
 * @variable: Input user
 * @check_exit: Check exit status
 * @env_var: Environment variable
 * @args: Name of program
 * Return: 1 if true, 0 if false
 */
int support_func(char **input, char *variable, int check_exit,
		 char **env_var, char *args)
{
	if (!str_cmp(input[0], "exit"))
		exit_command(input, variable, check_exit);
	if (!str_cmp(input[0], "setenv"))
	{
		set_env(input);
		return (0);
	}
	if (!str_cmp(input[0], "unsetenv"))
	{
		unset_env(input);
		return (0);
	}
	if (!str_cmp(input[0], "env"))
	{
		env_check(env_var);
		return (0);
	}
	if (!str_cmp(input[0], "$$") || !str_cmp(input[0], "$?"))
		replacement_check(&input[0], check_exit);
	if (!str_cmp(input[0], "echo"))
	{
		if (input[1] == NULL)
		{
			write(1, "\n", 1);
			return (0);
		}
		echo_check(input, check_exit, env_var);
		return (0);
	}
	if (!str_cmp(input[0], "cd"))
	{
		cd_func(input, args);
		return (0);
	}
	return (-1);
}

/**
 * echo_check - Function to check echo command
 * @input: Tokenise input
 * @check_exit: Check exit status
 * @env_var: Enviroment variables
 */
void echo_check(char **input, int check_exit, char **env_var)
{
	pid_t pid_set = getpid();
	char pid_s[32], exit_s[32];
	char *loc;
	int y;

	func_itoa(pid_set, pid_s, 10);
	func_itoa(check_exit, exit_s, 10);
	for (y = 1; input[y] != NULL; y++)
	{
		if (y > 1)
			puts_(" ");
		if (!str_cmp(input[y], "$?"))
		{
			write(1, exit_s, str_len(exit_s));
			continue;
		}
		if (!str_cmp(input[y], "$$"))
		{
			write(1, pid_s, str_len(pid_s));
			continue;
		}
		if (!str_cmp(input[y], "$PATH"))
		{
			loc = path_finder(env_var);
			puts_(loc);
			free(loc);
			continue;
		}
		puts_(input[y]);
	}
	puts_("\n");
}

/**
 * replacement_check - Function to check replacement of $? and $$
 * @input: Command replacement adress
 * @check_exit: Exit status checker
 */
void replacement_check(char **input, int check_exit)
{
	pid_t pid_set = getpid();

	if (!str_cmp(*input, "$$"))
		func_itoa(pid_set, *input, 10);

	if (!str_cmp(*input, "$?"))
		func_itoa(check_exit, *input, 10);
}

/**
 * set_env - Function that sets environ variable
 * @tok_command: Tokenizes user's command
 * Return: NULL
 */
void set_env(char **tok_command)
{
	int o_write = 1, t;

	if (tok_command[1] == NULL || tok_command[2] == NULL)
	{
		puts_("setenv: Too few arguments \n");
		return;
	}
	if (tok_command[3] != NULL)
	{
		puts_("setenv: Too many arguments \n");
		return;
	}

	t = setenv(tok_command[1], tok_command[2], o_write);

	if (t != 0)
		perror("setenv");
}

/**
 * unset_env - Function to unset env
 * @toks_command: Tokenize user's command
 * Return: NULL
 */
void unset_env(char **tok_command)
{
	int t;

	if (tok_command[1] == NULL)
	{
		puts_("unsetenv: Too few arguments \n");
		return;
	}
	if (tok_command[2] != NULL)
	{
		puts_("unsetenv: Too many arguments \n");
		return;
	}

	t = unsetenv(tok_command[1]);

	if (t != 0)
		perror("unsetenv");
}
