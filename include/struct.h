/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

/* INCLUDES */
    #include "lib.h"

/* ENV LINKED LIST */
typedef struct env_s {
    char *str;
    struct env_s *next;
    struct env_s *previous;
} env_l;

typedef struct control_env_s {
    struct env_s *begin;
    struct env_s *last;
} control_env_l;
#endif /* !STRUCT_H_ */
