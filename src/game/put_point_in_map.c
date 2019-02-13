/*
** EPITECH PROJECT, 2017
** put_point_map_me
** File description:
** put_point_map_me
*/

#include "header_navy.h"
#include "my.h"

int	put_point_map_me(map_t *map, point_t *p)
{
	switch (map->map[p->y][p->x]) {
		case 0: map->map[p->y][p->x] = -2;
			return (0);
		case -2: return (0);
			break;
		case -1: return (1);
		default: map->map[p->y][p->x] = -1;
			return (1);
	}
}

int	put_point_map_enemy(map_t *map, point_t *p, int value)
{
	switch (value) {
		case 1: map->map[p->y][p->x] = 1;
			break;
		case 0: map->map[p->y][p->x] = 2;;
			break;
	}
	return (1);
}
