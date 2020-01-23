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

void get_params_ai(int *line, int *matches, int *board, int max_matches)
{
    int last_line = 0;

    last_line = get_last_line(board);
    if (last_line != 0) {
        *line = last_line;
        get_params_last_line(*line, matches, board, max_matches);
    } else {
        get_move_marienbad(line, matches, board, max_matches);
    }
}

int get_last_line(int *board)
{
    int last_line = 0;

    for (int i = 1; i <= board[0]; i++) {
        if (board[i] != 0 && last_line == 0)
            last_line = i;
        else if (board[i] != 0 && last_line != 0)
            return (0);
    }
    return (last_line);
}

void get_params_last_line(int line, int *matches, int *board, int max_matches)
{
    *matches = (board[line] - 1) % (max_matches + 1);
    if (*matches == 0)
        *matches = 1;
}