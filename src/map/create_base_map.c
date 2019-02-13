/*
** EPITECH PROJECT, 2017
** create_base_map
** File description:
** create_base_map
*/

#include "header_navy.h"
#include <stdlib.h>

map_t	*malloc_map(int x, int y)
{
	map_t *map = malloc(sizeof(*map));
	int i = 0;

	if (map == NULL)
		return (NULL);
	map->map = malloc(sizeof(*map->map) * y);
		if (map->map == NULL) {
			free(map);
			return (NULL);
		}
	while (i != y) {
		map->map[i] = malloc(sizeof(int) * x);
		if (map->map[i] == NULL) {
			free(map->map);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}
map_t	*create_base_map(int x, int y)
{
	map_t *map = malloc_map(x, y);
	int i = 0;
	int j = 0;

	if (map == NULL)
		return (NULL);
	map->x = x;
	map->y = y;
	while (i != y) {
		j = 0;
		while (j != x)
			map->map[i][j++] = 0;
		i++;
	}
	return (map);
}
