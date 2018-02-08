/*
** EPITECH PROJECT, 2017
** how_long_map
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_navy.h"

int	verify_coordonate(int x, int y);
point_t	*put_coordonate_in_point(char col, char line);
int	absolue(int var);

Test(verify_coordonate, test1)
{
	cr_assert_eq(verify_coordonate(0, 0), 1);
	cr_assert_eq(verify_coordonate(0, 8), 0);
	cr_assert_eq(verify_coordonate(0, -1), 0);
	cr_assert_eq(verify_coordonate(-1, 0), 0);
	cr_assert_eq(verify_coordonate(8, 0), 0);
}

Test(put_coordonate_in_point, test1)
{
	point_t *point = put_coordonate_in_point('A', '1');

	cr_assert_neq(point, NULL);
	cr_assert_eq(point->x, 0);
	cr_assert_eq(point->y, 0);
	free(point);
	point = put_coordonate_in_point('I', '0');
	cr_assert_eq(point, NULL);
}
Test(absolue, test1)
{
	int var = absolue(-1);

	cr_assert_eq(var, 1);
	var = absolue(0);
	cr_assert_eq(var, 0);
	var = absolue(1);
	cr_assert_eq(var, 1);
}
