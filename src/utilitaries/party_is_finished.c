/*
** EPITECH PROJECT, 2017
** party_is_finished
** File description:
** party_is_finished
*/

#include "header_navy.h"
#include "my.h"
#include <stdio.h>

int	me_all_find(map_t *map)
{
	int x = 0;
	int y = 0;

	while (y != map->y) {
		x = 0;
		while (x != map->x)
			if (map->map[y][x++] > 0)
				return (0);
		y++;
	}
	return (1);
}

int	enemy_all_find(map_t *map)
{
	int res = 0;
	int x = 0;
	int y = 0;

	while (y != map->y) {
		x = 0;
		while (x != map->x) {
			if (map->map[y][x++] == 1)
				res++;
		}
		y++;
	}
	if (res < SIZE)
		return (0);
	return (1);
}

int	party_is_finished(navy_t *nav)
{
	if (enemy_all_find(nav->map_you) == 1)
		return (1);
	if (me_all_find(nav->map_me) == 1)
		return (2);
	return (0);
}
