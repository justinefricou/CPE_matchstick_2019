/*
** EPITECH PROJECT, 2020
** display_board.c
** File description:
** matchstick : displays the board
*/

#include "matchstick.h"

void display_board(int *board)
{
    display_frame(board[0]);
    display_matches(board[0], &(board)[1]);
    display_frame(board[0]);
}

void display_frame(int nb_lines)
{
    for (int i = 0; i < nb_lines * 2 + 1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
}

void display_matches(int nb_lines, int *board)
{
    for (int line = 0; line < nb_lines; line++) {
        write(1, "*", 1);
        for (int i = 0; i < nb_lines - line - 1; i++)
            write(1, " ", 1);
        for (int i = 0; i < board[line]; i++)
            write(1, "|", 1);
        for (int i = 0; i < (2 * line + 1) - board[line]; i++)
            write(1, " ", 1);
        for (int i = 0; i < nb_lines - (2 * line + 1) / 2 - 1; i++)
            write(1, " ", 1);
        write(1, "*\n", 2);
    }
}