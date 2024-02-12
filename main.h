#ifndef MAIN_H
#define MAIN_H

/*libraries*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* definations */
#define EXIT WIFEXITED
#define STATUS WEXITSTATUS

/* prototype functions */
char *get_input(void);
void exit_command(char **token, char *line, int done);
void env_check(char **env_var);
char *path_finder(char **env_var);
int path_handler(char **token, char **env_var);
char **tokenizer(char *args);
unsigned int delimeter_check(char ch, const char *s);
char *str_tok(char *s, const char *mark);
void cd_func(char **input, char *prog_nm);
void unset_env(char **tok_command);
void set_env(char **tok_command);
void replacement_check(char **input, int check_exit);
void echo_check(char **input, int check_exit, char **env_var);
int support_func(char **input, char *variable, int check_exit,
                 char **env_var, char *args);
int exe_func(char **input, char **args, char **env_var, char *command, int loc_output,
             int pid);
void output_err(char *identifier, int pid, char *input);

/* string prototype functions */
int str_cmp(char *str1, char *str2);
int str_len(char *s);
size_t str_bytecmp(char *str1, char *str2, size_t nmbr);
char *str_cat(char *to, char *from);
char *str_cpy(char *to, char *from);
int func_atoi(char *str);
void func_itoa(int p, char *s, int station);
void str_rev(char *s);
char *str_dup(const char *s);

/* printing prototype function */
int puts_(char *s);
int putchar_(char ch);

#endif
