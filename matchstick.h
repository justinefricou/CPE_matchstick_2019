/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** matchstick : header
*/

#ifndef DEF_MATCHSTICK
#define DEF_MATCHSTICK

#include <stdlib.h>
#include <unistd.h>

// error_detection.c
int detect_errors(int argc, char **argv);
int is_int(char *str);

// get_board.c
int create_board(int **board, int nb_lines);
int my_get_nbr(char *s);

// play.c
int play(int *board, int max_matches);
void update_board(int *board, int line, int nb_matches, int players_turn);
int my_put_nbr(int nbr);
void display_end_message(int winner);

// display_board.c
void display_board(int *board);
void display_frame(int nb_lines);
void display_matches(int nb_lines, int *board);

#endif // DEF_MATCHSTICK