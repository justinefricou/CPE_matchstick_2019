/*
** EPITECH PROJECT, 2020
** marienbad.c
** File description:
** matchstick : ai's moves based on marienbad game's winning strategy
*/

#include "matchstick.h"

void get_move_marienbad(int *line, int *matches, int *board, int max_matches)
{
    int odd_nbrs = 8;
    int test_match = 1;

    for (int i = 1; i <= board[0]; i++) {
        get_best_move_on_line(i, &test_match, board, max_matches);
        board[i] -= test_match;
printf("line : %i, matches : %i, odd_nbrs : %i\n", i, test_match, odd_nbrs);
        if (board[*line] + test_match > 0 && get_odd_nbrs(board) <= odd_nbrs) {
            *line = i;
            *matches = test_match;
            odd_nbrs = get_odd_nbrs(board);
        }
        board[i] += test_match;
    }
}

void add_nbr_to_columns(int nbr, int columns[])
{
    for (int exponent = 7; exponent >= 0; exponent--) {
        if ((1 << exponent) <= nbr) {
            columns[7 - exponent] += 1;
            nbr -= (1 << exponent);
        }
    }
}

int get_odd_nbrs(int *board)
{
    int columns[8] = {0};
    int odd_nbrs = 0;

    for (int i = 1; i <= board[0]; i++)
        add_nbr_to_columns(board[i], columns);
    for (int i = 0; i < 8; i++) {
        if (columns[i] % 2 != 0)
            odd_nbrs++;
    }
    return (odd_nbrs);
}

int get_best_move_on_line(int line, int *matches, int *board, int max_matches)
{
    int odd_nbrs = 8;

    if (board[line] <= 0)
        return (0);
    for (int i = 1; i <= max_matches && i <= board[line]; i++) {
printf("matches : %i, odd_nbrs : %i\n", i, odd_nbrs);
        board[line] -= i;
        if (get_odd_nbrs(board) <= odd_nbrs) {
            *matches = i;
            odd_nbrs = get_odd_nbrs(board);
        }
        board[line] += i;
    }
    return (0);
}
