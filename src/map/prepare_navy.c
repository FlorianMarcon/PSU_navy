/*
** EPITECH PROJECT, 2017
** prepare_map
** File description:
** prepare_map
*/

#include <stdlib.h>
#include "header_navy.h"
#include "my.h"
void	destroy_list_coord(coord_t **cor);
int	put_list_point_in_map_first(map_t *map, linked_list_t *list);
coord_t	**get_coordonate(char *path);
map_t	*create_base_map(int x, int y);
linked_list_t	*create_list_point_by_coord(coord_t **cor);

navy_t	*prepare_nav(char *path)
{
	navy_t *nav = malloc(sizeof(*nav));
	coord_t **cor = get_coordonate(path);
	linked_list_t *list = NULL;

	if (nav == NULL || cor == NULL)
		return (NULL);
	nav->map_me = create_base_map(8, 8);
	nav->map_you = create_base_map(8, 8);
	list = create_list_point_by_coord(cor);
	destroy_list_coord(cor);
	if (list == NULL) {
		free(nav);
		return (NULL);
	}
	put_list_point_in_map_first(nav->map_me, list);
	return (nav);
}
