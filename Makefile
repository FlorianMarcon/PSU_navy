##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\
		$(WAY)/navy.c		\
		$(WAY)/first_player/first_player.c	\
		$(WAY)/second_player/second_player.c	\
		$(WAY)/utilitaries/inutile_function.c	\
		$(WAY)/utilitaries/verify_coordonate.c	\
		$(WAY)/utilitaries/put_coordonate_in_point.c	\
		$(WAY)/utilitaries/destroy_coord.c	\
		$(WAY)/utilitaries/absolue.c		\
		$(WAY)/utilitaries/register_pid.c	\
		$(WAY)/utilitaries/verify_connexion.c	\
		$(WAY)/utilitaries/destroy_nav.c	\
		$(WAY)/map/create_base_map.c		\
		$(WAY)/map/display_map.c		\
		$(WAY)/map/put_point_in_map.c		\
		$(WAY)/map/prepare_navy.c		\
		$(WAY)/get_coordonate/get_coordonate.c	\
		$(WAY)/get_coordonate/put_data_in_coord.c	\
		$(WAY)/get_coordonate/create_list_point_by_coord.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I./include

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	navy

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C./$(WAY_TST)
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_TST)
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
