#include "main.h"

/**
 * cd_func - Function that changes a directory like cd.
 * @input: Arguments
 * @prog_nm: Name of the program
 */
void cd_func(char **input, char *prog_nm)
{
	int no = -1;
	char func_cwd[PATH_MAX];

	if (input[1] == NULL)
		no = chdir(getenv("HOME"));
	else if (str_cmp(input[1], "-") == 0)
		no = chdir(getenv("OLDPWD"));
	else
		no = chdir(input[1]);

	if (no == -1)
	{
		perror(prog_nm);
		return;
	}
	else if (no != -1)
	{
		getcwd(func_cwd, sizeof(func_cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", func_cwd, 1);
	}
}
