#include "main.h"

/**
 * exe_func - Function to execute command
 * @input: Cmd line argument
 * @args: Name of program
 * @env_var: env variable
 * @command: User input
 * @loc_output: Pathfinder
 * @pid: Proccess identifier
 * Return: 0 if successful
 */
int exe_func(char **input, char **args, char **env_var, char *command, int loc_output,
		int pid)
{
	pid_t begins;
	int cur, check_end;

	begins = fork();

	if (begins == 0)
	{
		if (execve(input[0], input, env_var) == -1)
		{
			output_err(args[0], pid, input[0]);
			if (!loc_output)
				free(input[0]);
			free(input);
			free(command);
			exit(errno);
		}
	}
	else if (begins == -1)
	{
		perror(args[0]);
		if (!loc_output)
			free(input[0]);
		free(input);
		free(command);
		exit(errno);
	}
	else
	{
		wait(&cur);
		if (EXIT(cur))
		{
			check_end = STATUS(cur);
			return (check_end);
		}
	}
	return (0);
}

/**
 * output_err - Displays error message
 * @identifier: Program name
 * @pid: Process ID
 * @input: Unavailable command
 */
void output_err(char *identifier, int pid, char *input)
{
	char order[32];

	func_itoa(pid, order, 10);

	puts_(identifier);
	puts_(": ");
	puts_(order);
	puts_(": ");
	puts_(input);
	puts_(": not found\n");
}
