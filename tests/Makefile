##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/navy.c		\
		$(WAY)/first_player/first_player.c	\
		$(WAY)/first_player/game_first_player.c	\
		$(WAY)/second_player/second_player.c	\
		$(WAY)/second_player/game_second_player.c	\
		$(WAY)/utilitaries/inutile_function.c	\
		$(WAY)/utilitaries/verify_coordonate.c	\
		$(WAY)/utilitaries/put_coordonate_in_point.c	\
		$(WAY)/utilitaries/destroy_coord.c	\
		$(WAY)/utilitaries/absolue.c		\
		$(WAY)/utilitaries/register_pid.c	\
		$(WAY)/utilitaries/verify_connexion.c	\
		$(WAY)/utilitaries/destroy_nav.c	\
		$(WAY)/utilitaries/recuperate_info.c	\
		$(WAY)/utilitaries/party_is_finished.c	\
		$(WAY)/utilitaries/send_message.c	\
		$(WAY)/utilitaries/translate_coordonate.c	\
		$(WAY)/map/create_base_map.c		\
		$(WAY)/map/display_map.c		\
		$(WAY)/map/put_point_in_map.c		\
		$(WAY)/map/prepare_navy.c		\
		$(WAY)/get_coordonate/get_coordonate.c	\
		$(WAY)/get_coordonate/put_data_in_coord.c	\
		$(WAY)/get_coordonate/create_list_point_by_coord.c	\
		$(WAY)/game/receive_message.c		\
		$(WAY)/game/wait_message.c		\
		$(WAY)/game/put_point_in_map.c		\

SRC_UT	=	./utilitaries/tests_utils.c	\
		./utilitaries/tests_utils_second.c	\
		./utilitaries/tests_utils_third.c	\
		./utilitaries/tests_utils_four.c	\
		./map/tests_utils.c		\
		./map/tests_utils_second.c	\
		./map/tests_utils_third.c	\
		./map/tests_utils_four.c	\
		./map/tests_utils_five.c	\
		./get_coordonate/tests_utils.c	\
		./get_coordonate/tests_utils_second.c	\
		./get_coordonate/tests_utils_third.c	\
		./get_coordonate/tests_utils_four.c	\
		./game/tests_utils.c		\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage -I../include

LDFLAGS	=	-lcriterion -lgcov

WAY_LIB	=	../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

all:	$(OBJ) $(OBJ_UT)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	$(RM) $(NAME)

re:	clean all
