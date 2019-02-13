/*
** EPITECH PROJECT, 2017
** display_map
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_navy.h"

void	choice_display_enemy(int x, int y, map_t *map);
void	display_map_enemy(map_t *map);
map_t	*create_base_map(int x, int y);

map_t	*mmaapp(void)
{
	map_t *map = create_base_map(8, 8);

	if (map == NULL)
		return (NULL);
	map->map[0][1] = 1;
	map->map[0][7] = 2;
	return (map);
}
Test(choice_display_enemy, test1)
{
	map_t *map = mmaapp();

	cr_redirect_stdout();
	choice_display_enemy(0, 1, map);
	cr_assert_stdout_eq_str("x ");
	free(map->map);
	free(map);
}
Test(choice_display_enemy, test2)
{
	map_t *map = mmaapp();

	cr_redirect_stdout();
	choice_display_enemy(0, 0, map);
	cr_assert_stdout_eq_str(". ");
	free(map->map);
	free(map);
}

Test(choice_display_enemy, test3)
{
	map_t *map = mmaapp();

	cr_redirect_stdout();
	choice_display_enemy(0, 7, map);
	cr_assert_stdout_eq_str("o\n");
	free(map->map);
	free(map);
}
Test(display_map_enemy, test1)
{
	char real[] = " |A B C D E F G H\n\
-+---------------\n1|. x . . . . . o\n2|. . . . . . . .\n3|. . . . . . . .\n\
4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n\
8|. . . . . . . .\n\n\n";
	map_t *map = mmaapp();

	cr_redirect_stdout();
	display_map_enemy(map);
	cr_assert_stdout_eq_str(real);
	free(map->map);
	free(map);
}
