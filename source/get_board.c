/*
** EPITECH PROJECT, 2020
** get_board.c
** File description:
** matchstick : creates the board and fills it with the matches
*/

#include "matchstick.h"

int create_board(int **board, int nb_lines)
{
    *board = malloc(sizeof(int) * (nb_lines + 2));
    if (*board == NULL)
        return (84);
    (*board)[0] = nb_lines;
    for (int i = 1; i < nb_lines + 1; i++)
        (*board)[i] = 2 * (i - 1) + 1;
    (*board)[nb_lines + 1] = -1;
    return (0);
}

int my_get_nbr(char *s)
{
    int nbr = 0;
    int i = 0;

    for ( ; s[i] == '-' || s[i] == '+' || s[i] == '0'; i++);
    for ( ; s[i] != 0; i++)
        nbr = nbr * 10 + (s[i] - 48);
    if (s[0] == '-')
        nbr = nbr * (-1);
    return (nbr);
}