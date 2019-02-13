/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_navy.h"
map_t	*create_base_map(int x, int y);

Test(create_base_map, test1)
{
	int var = 3;
	map_t *map = create_base_map(var, var);
	int i = 0;
	int j = 0;

	cr_assert_eq(map->x, var);
	cr_assert_eq(map->y, var);
	while (i != var) {
		j = 0;
		while (j != var) {
			cr_assert_eq(map->map[i][j], 0);
			j++;
		}
		i++;
	}
}
