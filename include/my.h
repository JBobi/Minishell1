/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** project's header
*/


#ifndef MY_H_
    #define MY_H_

/* DEFINE */
    #define _GNU_SOURCE
    #define EXIT_SUCCESS 0
    #define EXIT_ERROR 84
    #define TRUE 1

/* INCLUDE */
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <errno.h>
    #include "struct.h"

/* GLOBAL FUNCTION */
void minishell(int ac, char **av, char **env);

/* NEW COMMANDS */
void execute_exit(char **command, control_env_l *control);
void execute_env(control_env_l *control);
void execute_setenv(char **command, control_env_l *control);
void execute_unsetenv(char **command, control_env_l *control);
void create_env_var(char *name, control_env_l *control);
int is_alphanum(char *name);
int verify_variable_setenv_name(char *name);
char *reset_value(char *var);
char *give_value(char *var, char *value);
env_l *find_variable(char *name, control_env_l *control);
void execute_cd(char **command, control_env_l *control);
char *get_env_value(char *var_name, control_env_l *control);

/* GET COMMAND */
int count_words(char *str);
char *get_command(control_env_l *control);
char **transform_array(char *command);
char **get_command_tab(control_env_l *control);
char *add_bin_path(char *command);

/* CHECK SYSTEM CALL */
int check_system_call(char **tab, control_env_l *control);
int check_path(char *path);

/* EXECUTES FUNCTION */
void execute_function(char **command, control_env_l *control);
void run_command(char **command, control_env_l *control);
void handle_signal(int status);
void handle_quit_signal(int status);

/* ENV LIST */
void create_env_list(char **env, control_env_l *control);
env_l *create_env_node(char *env);
control_env_l *create_control_env(char **env);
void free_env_list(control_env_l *control);
int list_len(env_l *list);
char **transform_env(control_env_l *list);

#endif /* !MY_H_ */
