/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my.h"
int	put_point_map_me(map_t *map, point_t *p);
navy_t	*prepare_nav(char *path);
int	put_point_map_enemy(map_t *map, point_t *p, int value);

Test(put_point_map_me, test1)
{
	navy_t *nav = prepare_nav("data/real_coordonate");
	point_t p = {0, 0, 0};

	cr_assert_eq(put_point_map_me(nav->map_me, &p), 0);
	cr_assert_eq(nav->map_me->map[0][0], -2);
	cr_assert_eq(put_point_map_me(nav->map_me, &p), 0);
	cr_assert_eq(nav->map_me->map[0][0], -2);
}

Test(put_point_map_me, test2)
{
	navy_t *nav = prepare_nav("data/real_coordonate");
	point_t p = {2, 0, 0};

	cr_assert_eq(put_point_map_me(nav->map_me, &p), 1);
	cr_assert_eq(nav->map_me->map[0][2], -1);
	cr_assert_eq(put_point_map_me(nav->map_me, &p), 1);
	cr_assert_eq(nav->map_me->map[0][2], -1);
}

Test(put_point_map_enemy, test1)
{
	navy_t *nav = prepare_nav("data/real_coordonate");
	point_t p = {0, 0, 0};

	cr_assert_eq(put_point_map_enemy(nav->map_you, &p, 1), 1);
	cr_assert_eq(nav->map_you->map[0][0], 1);
	cr_assert_eq(put_point_map_enemy(nav->map_you, &p, 0), 1);
	cr_assert_eq(nav->map_you->map[0][0], 2);
}
