/*
** EPITECH PROJECT, 2017
** test
** File description:
** prepare_map
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my.h"
navy_t	*prepare_nav(char *path);
void	display_map_me(map_t *map);

Test(prepare_nav, test1)
{
	navy_t *nav = prepare_nav("");
	cr_assert_eq(nav, NULL);
}

Test(prepare_nav, test2)
{
	navy_t *nav = prepare_nav("data/real_coordonate");
	cr_assert_neq(nav, NULL);
	int x = 0;
	int y = 0;

	while (y != 8) {
		x = 0;
		while (x != 8)
			cr_assert_eq(nav->map_you->map[y][x++], 0);
		y++;
	}
	cr_assert_eq(nav->map_me->map[0][2], 2);
	cr_assert_eq(nav->map_me->map[1][2], 2);
	cr_assert_eq(nav->map_me->map[3][3], 3);
	cr_assert_eq(nav->map_me->map[3][4], 3);
	cr_assert_eq(nav->map_me->map[3][5], 3);
	cr_assert_eq(nav->map_me->map[4][1], 4);
	cr_assert_eq(nav->map_me->map[5][1], 4);
	cr_assert_eq(nav->map_me->map[6][1], 4);
	cr_assert_eq(nav->map_me->map[7][1], 4);
	cr_assert_eq(nav->map_me->map[6][3], 5);
	cr_assert_eq(nav->map_me->map[6][4], 5);
	cr_assert_eq(nav->map_me->map[6][5], 5);
	cr_assert_eq(nav->map_me->map[6][6], 5);
	cr_assert_eq(nav->map_me->map[6][7], 5);
}
