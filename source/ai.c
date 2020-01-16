/*
** EPITECH PROJECT, 2020
** ai.c
** File description:
** matchstick : ai moves
*/

#include "matchstick.h"

void ais_turn(int *board, int max_matches, int *winner)
{
    int line = 0;
    int nb_matches = 0;

    write(1, "\nAI's turn...\n", 14);
    get_params_ai(&line, &nb_matches, board, max_matches);
    update_board(board, line, nb_matches, 0);
    if (no_matches_remaining(board))
        *winner = 1;
}

/* [min, max[ :
*line = random() % (max - min + 1) + min;
*matches = random() % (max - min + 1) + min;*/
void get_params_ai(int *line, int *matches, int *board, int max_matches)
{
    while (*line <= 0 && *matches <= 0) {
        *line = random() % (board[0]) + 1;
        *matches = random() % (max_matches) + 1;
        if (*matches > board[*line]) {
            *line = 0;
            *matches = 0;
        }
    }
}