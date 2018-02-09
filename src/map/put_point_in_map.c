/*
** EPITECH PROJECT, 2017
** put_point_in_map
** File description:
** put_point_in_map
*/

#include "header_navy.h"
#include "my.h"

void	put_point_in_map(map_t *map, point_t *point)
{
	map->map[point->y][point->x] = point->value;
}

int	put_list_point_in_map_first(map_t *map, linked_list_t *list)
{
	linked_list_t *tmp = list;
	point_t *p;

	while (tmp != NULL) {
		p = (point_t *)(tmp->data);
		put_point_in_map(map, p);
		tmp = tmp->next;
	}
	return (0);
}
