#include "main.h"

/**
 * main - Simple shell function
 * @ac: Argument count
 * @av: Array of argument
 * @env_var: Env variable
 *
 * Return: Result
 */
int main(int __attribute__((unused)) ac, char **av, char **env_var)
{
	char *user_cmd = NULL, **args = NULL;
	int check_exit = 0, o_res = 0;
	int proc_ = 0;

	while (1)
	{
		user_cmd = get_input();
		if (!user_cmd)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(check_exit);
		}
		else
		{
			proc_++;
			args = tokenizer(user_cmd);
			if (!args)
			{
				free(args);
				continue;
			}
			check_exit = support_func(args, user_cmd, check_exit,
						   env_var, av[0]);
			if (check_exit == -1)
			{
				o_res = path_handler(&args[0], env_var);
				check_exit = exe_func(args, av, env_var,
						      user_cmd, o_res,
						      proc_);
				if (o_res == 0)
					free(args[0]);
			}
			free(args);
		}
		free(user_cmd);
	}
	return (check_exit);
}
