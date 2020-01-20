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
#include <stdio.h>
#include <time.h>

// error_detection.c
int detect_errors(int argc, char **argv);
int is_positive_int(char *str);

// get_board.c
int create_board(int **board, int nb_lines);
int my_get_nbr(char *s);

// display_board.c
void display_board(int *board);
void display_frame(int nb_lines);
void display_matches(int nb_lines, int *board);

// play.c
int play(int *board, int max_matches);
void update_board(int *board, int line, int nb_matches, int players_turn);
int no_matches_remaining(int *board);
void display_end_message(int winner);
int my_put_nbr(int nbr);

// player_interactions.c
int players_turn(int *board, int max_matches, int *winner);
int read_params(int *line, int *nb_matches, int *board, int max_matches);
int get_line(char **buffer, int *line, int nb_lines);
int get_matches(char **buf, int *matches, int max_matches, int remaining_mat);
int check_nb_matches(int nb_matches, int max_matches, int remaining_matches);

// ai.c
void ais_turn(int *board, int max_matches, int *winner);
void get_params_ai(int *line, int *matches, int *board, int max_matches);
int get_last_line(int *board);
void get_params_last_line(int line, int *matches, int *board, int max_matches);
void get_random_params(int *line, int *matches, int *board, int max_matches);

#endif // DEF_MATCHSTICK