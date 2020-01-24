##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A Makefile to compile matchstick
##

NAME	=	matchstick

SRC	=	source/main.c\
		source/error_detection.c\
		source/get_board.c\
		source/display_board.c\
		source/play.c\
		source/player_interactions.c\
		source/ai.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./

NAME_TESTS	=	tests_matchstick

SRC_TESTS	=

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TESTS)

fclean:	clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)
		rm -f *.gcno
		rm -f *.gcda

re:	fclean all

tests_run:	$(SRC_TESTS)
			rm -f *.gcno
			rm -f *.gcda
			gcc -o $(NAME_TESTS) $(SRC_TESTS) $(CFLAGS) --coverage -lcriterion
			./$(NAME_TESTS)