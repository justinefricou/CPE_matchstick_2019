/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** matchstick : main function
*/

#include "matchstick.h"

int main(int argc, char **argv)
{
    int *board = NULL;
    int nb_lines = 0;
    int max_matches = 0;
    int winner = 0;

    if (detect_errors(argc, argv))
        return (84);
    nb_lines = my_get_nbr(argv[1]);
    max_matches = my_get_nbr(argv[2]);
    if (nb_lines <= 0 || max_matches <= 0)
        return (84);
    if (create_board(&board, nb_lines) == 84)
        return (84);
    winner = play(board, max_matches); //
    free(board);
    return (winner);
}