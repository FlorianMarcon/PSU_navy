/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my.h"
int	me_all_find(map_t *map);
int	enemy_all_find(map_t *map);
int	party_is_finished(navy_t *nav);
map_t	*create_base_map(int x, int y);

Test(me_all_find, test1)
{
	map_t *map = create_base_map(8, 8);

	cr_assert_eq(me_all_find(map), 1);
	map->map[0][0] = 1;
	cr_assert_eq(me_all_find(map), 0);
}

Test(enemy_all_find, test1)
{
	map_t *map = create_base_map(8, 8);
	int i = 0;

	cr_assert_eq(enemy_all_find(map), 0);

	while (i != 8)
		map->map[0][i++] = 1;
	i = 0;
	while (i != 6)
		map->map[1][i++] = 1;
	cr_assert_eq(enemy_all_find(map), 1);
}

Test(party_is_finished, test1)
{
	navy_t *nav = malloc(sizeof(*nav));

	nav->map_me = create_base_map(8, 8);
	nav->map_you = create_base_map(8, 8);

	cr_assert_eq(party_is_finished(nav), 2);
}

Test(party_is_finished, test2)
{
	navy_t *nav = malloc(sizeof(*nav));
	map_t *map;
	int i = 0;

	nav->map_me = create_base_map(8, 8);
	nav->map_you = create_base_map(8, 8);
	map = nav->map_you;
	while (i != 8)
		map->map[0][i++] = 1;
	i = 0;
	while (i != 6)
		map->map[1][i++] = 1;
	cr_assert_eq(party_is_finished(nav), 1);
}
Test(party_is_finished, test3)
{
	navy_t *nav = malloc(sizeof(*nav));

	nav->map_me = create_base_map(8, 8);
	nav->map_you = create_base_map(8, 8);

	nav->map_me->map[0][0] = 2;
	cr_assert_eq(party_is_finished(nav), 0);
}
