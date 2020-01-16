/*
** EPITECH PROJECT, 2020
** error_detection.c
** File description:
** matchstick : returns 84 if wrong nb of args of if they aren't ints
*/

#include "matchstick.h"

int detect_errors(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    if (!is_int(argv[1]) || !is_int(argv[2]))
        return (84);
    return (0);
}

int is_int(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    for ( ; str[i] != 0; i++) {
        if (str[i] < '0' || '9' < str[i])
            return (0);
    }
    return (1);
}