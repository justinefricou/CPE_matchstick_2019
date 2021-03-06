/*
** EPITECH PROJECT, 2020
** play.c
** File description:
** matchstick : the game loop
*/

#include "matchstick.h"

int play(int *board, int max_matches)
{
    int winner = 0;

    display_board(board);
    while (1) {
        if (players_turn(board, max_matches, &winner) == 0)
            return (0);
        display_board(board);
        if (winner != 0)
            break;
        ais_turn(board, max_matches, &winner);
        display_board(board);
        if (winner != 0)
            break;
    }
    display_end_message(winner);
    return (winner);
}

void update_board(int *board, int line, int nb_matches, int players_turn)
{
    board[line] -= nb_matches;
    if (players_turn)
        write(1, "Player removed ", 15);
    else
        write(1, "AI removed ", 11);
    my_put_nbr(nb_matches);
    write(1, " match(es) from line ", 21);
    my_put_nbr(line);
    write(1, "\n", 1);
}

int no_matches_remaining(int *board)
{
    for (int i = 0; i < board[0]; i++) {
        if (board[i + 1] != 0)
            return (0);
    }
    return (1);
}

void display_end_message(int winner)
{
    if (winner == 2)
        write (1, "You lost, too bad...\n", 21);
    else
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
}

int my_put_nbr(int nbr)
{
    char character = 0;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr = nbr * -1;
    }
    if (nbr >= 10)
        my_put_nbr(nbr / 10);
    character = nbr % 10 + 48;
    write(1, &character, 1);
    return (0);
}