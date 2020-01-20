/*
** EPITECH PROJECT, 2020
** player_interactions.c
** File description:
** matchstick : read player's input and update the board
*/

#include "matchstick.h"

int players_turn(int *board, int max_matches, int *winner)
{
    int line = 0;
    int nb_matches = 0;

    write(1, "\nYour turn:\n", 12);
    if (read_params(&line, &nb_matches, board, max_matches) == 0)
        return (0);
    update_board(board, line, nb_matches, 1);
    if (no_matches_remaining(board))
        *winner = 2;
    return (1);
}

int read_params(int *line, int *matches, int *board, int max_matches)
{
    char *buff_line = NULL;
    char *b_matches = NULL;
    int return_gl = -1;

    while (*line <= 0 && *matches <= 0) {
        while (return_gl == -1) {
            return_gl = get_line(&buff_line, line, board[0]);
            free(buff_line);
        }
        if (return_gl == 0)
                return (0);
        return_gl = get_matches(&b_matches, matches, max_matches, board[*line]);
        free(b_matches);
        if (return_gl == -1) {
            *line = 0;
            *matches = 0;
        } else if (return_gl == 0) {
            return (0);
        }
    }
    return (1);
}

int get_line(char **buffer, int *line, int nb_lines)
{
    ssize_t getline_size = 0;
    size_t n = 0;
    int length = 0;

    write(1, "Line: ", 6);
    getline_size = getline(buffer, &n, stdin);
    if (getline_size <= 0)
        return (getline_size == 0 ? -1 : 0);
    for (; (*buffer)[length] != '\n' && (*buffer)[length] != 0; length++);
    (*buffer)[length] = 0;
    if (!is_positive_int(*buffer)) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (-1);
    }
    *line = my_get_nbr(*buffer);
    if (*line == 0 || *line > nb_lines) {
        write(1, "Error: this line is out of range\n", 33);
        return (-1);
    }
    return (1);
}

int get_matches(char **buf, int *matches, int max_matches, int remaining_mat)
{
    ssize_t getline_size = 0;
    size_t n = 0;
    int length = 0;

    write(1, "Matches: ", 9);
    getline_size = getline(buf, &n, stdin);
    if (getline_size == -1)
        return (0);
    for (; (*buf)[length] != '\n' && (*buf)[length] != 0; length++);
    (*buf)[length] = 0;
    if (!is_positive_int(*buf)) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (-1);
    }
    *matches = my_get_nbr(*buf);
    if (check_nb_matches(*matches, max_matches, remaining_mat) == -1)
        return (-1);
    return (1);
}

int check_nb_matches(int nb_matches, int max_matches, int remaining_matches)
{
    if (nb_matches == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (-1);
    } else if (nb_matches > max_matches) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(max_matches);
        write(1, " matches per turn\n", 18);
        return (-1);
    }
    if (nb_matches > remaining_matches) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (-1);
    }
    return (0);
}