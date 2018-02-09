/*
** EPITECH PROJECT, 2017
** tests_utils_four
** File description:
** tests_utils_four
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "header_navy.h"
#include "my.h"
map_t	*create_base_map(int x, int y);
void	put_point_in_map(map_t *map, point_t *point);
int	put_list_point_in_map_first(map_t *map, linked_list_t *list);

Test(put_point_in_map, test1)
{
	map_t *map = create_base_map(8, 8);
	point_t p = {0, 0, 1};

	if (map != NULL) {
		put_point_in_map(map, &p);
		cr_assert_eq(map->map[0][0], 1);
	}
}

Test(put_list_point_in_map_first, test1)
{
	map_t *map = create_base_map(8, 8);
	point_t pa = {0, 0, 1};
	point_t pb = {0, 1, 2};
	linked_list_t *list = malloc(sizeof(*list) * 2);

	list[0].data = (void *)&pa;
	list[0].next = &list[1];
	list[1].data = (void *)&pb;
	list[1].next =  NULL;
	put_list_point_in_map_first(map, list);
	cr_assert_eq(map->map[0][0], 1);
	cr_assert_eq(map->map[1][0], 2);
	cr_assert_eq(map->map[3][3], 0);
}
