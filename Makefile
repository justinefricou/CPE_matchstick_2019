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

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all