/*
** EPITECH PROJECT, 2017
** first_player
** File description:
** first_player
*/

#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "my_printf.h"
#include "header_navy.h"
map_t	*create_base_map(int x, int y);

int	first_player(char *path)

	navy_t *nav = malloc(sizeof(*nav));
	coord_t **cor = get_coordonate(path);
	linked_list_t *list = NULL;

	if (nav == NULL || cor == NULL)
		return (-1);
	nav->map_me = create_base_map(8, 8);
	nav->map_you = create_base_map(8, 8);
	list = create_list_point_by_coord(cor);
	if (list == NULL)
		return (-1);
	return (1);
}
