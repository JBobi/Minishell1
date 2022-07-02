/*
** EPITECH PROJECT, 2022
** test_minishell.c
** File description:
** test
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test(count_words, test)
{
    int count = count_words("    count\n\n   words  ");

    cr_assert(count == 2);
}

Test(check_path, test)
{
    int file = check_path("tests/file");
    int wrong_file = check_path("wrong_file");
    int dir = check_path("tests/");

    cr_assert(file == 1);
    cr_assert(wrong_file == -1);
    cr_assert(dir == 1);
}

Test(add_bin_path, test)
{
    char *command = my_strdup("ls");

    command = add_bin_path(command);
    cr_assert_str_eq(command, "/bin/ls");
    free(command);
}

Test(is_alphanum, test)
{
    char name[] = "variable_name1";
    char wrong_name[] = "poutre$";

    cr_assert(is_alphanum(name) == 0);
    cr_assert(is_alphanum(wrong_name) == 1);
}

Test(verify_variable_setenv_name, test)
{
    char name[] = "_1name";
    char wrong_name1[] = "wr-ong";
    char wrong_name2[] = "7_wrong";

    cr_assert(verify_variable_setenv_name(name) == 0);
    cr_assert(verify_variable_setenv_name(wrong_name1) == 1);
    cr_assert(verify_variable_setenv_name(wrong_name2) == 2);
}

Test(my_count_array_size, test)
{
    char *tab[] = {"setenv", NULL};
    char *tab2[] = {"setenv", "var", "45", NULL};

    cr_assert(my_count_array_size(tab) == 1);
    cr_assert(my_count_array_size(tab2) == 3);
}

Test(list_len, test)
{
    env_l *node = create_env_node("env");
    env_l *temp = NULL;

    node->next = create_env_node("second env");
    node->next->next = create_env_node("third");
    node->next->next->next = create_env_node("another one");
    cr_assert(list_len(node) == 4);
    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
}
