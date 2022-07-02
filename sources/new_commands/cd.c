/*
** EPITECH PROJECT, 2022
** cd.c
** File description:
** cd
*/

#include "../../include/my.h"

char **create_cd_tab(char *var, char *pwd)
{
    char **to_return = malloc(sizeof(char *) * 4);

    if (to_return == NULL)
        return (NULL);
    to_return[0] = my_strdup("setenv");
    to_return[1] = my_strdup(var);
    to_return[2] = my_strdup(pwd);
    to_return[3] = NULL;
    return (to_return);
}

void change_pwd(control_env_l *control)
{
    size_t size = 200;
    char *pwd = malloc(sizeof(char) * (size + 1));
    char **command_pwd = NULL;
    char **command_oldpwd = NULL;
    char *pwd_value = NULL;

    if (pwd == NULL)
        return;
    getcwd(pwd, size);
    if ((pwd_value = get_env_value("PWD", control)) != NULL) {
        command_oldpwd = create_cd_tab("OLDPWD", pwd_value);
        execute_setenv(command_oldpwd, control);
        my_free_word_array(command_oldpwd);
    }
    command_pwd = create_cd_tab("PWD", pwd);
    execute_setenv(command_pwd, control);
    my_free_word_array(command_pwd);
    free(pwd);
}

void change_directory(char **command, control_env_l *control, int command_len)
{
    char *dir = NULL;

    if (command_len == 1 || (command_len == 2 &&
    (my_strcmp(command[1], "~") == 0 || command[1][0] == '$')))
        dir = get_env_value("HOME", control);
    else if (command_len == 2 && my_strcmp(command[1], "-") == 0)
        dir = get_env_value("OLDPWD", control);
    else
        dir = command[1];
    if (dir == NULL)
        return;
    chdir(dir);
    if (errno != 0) {
        my_putstr(dir, 2);
        my_putstr(": ", 2);
        my_putstr(strerror(errno), 2);
        my_putstr(".\n", 2);
    } else
        change_pwd(control);
}

void execute_cd(char **command, control_env_l *control)
{
    int command_len = my_count_array_size(command);

    if (command_len > 2)
        my_putstr("cd: Too many arguments.\n", 2);
    else
        change_directory(command, control, command_len);
}
