/*
** EPITECH PROJECT, 2017
** test
** File description:
** display_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_navy.h"

void	choice_display_me(int x, int y, map_t *map);
void	display_map_me(map_t *map);
map_t	*create_base_map(int x, int y);
map_t	*mmaapp(void);

Test(choice_display_me, test1)
{
	map_t *map = mmaapp();

	cr_redirect_stdout();
	choice_display_me(0, 1, map);
	cr_assert_stdout_eq_str("1 ");
	free(map->map);
	free(map);
}
Test(choice_display_me, test2)
{
	map_t *map = mmaapp();

	cr_redirect_stdout();
	choice_display_me(0, 0, map);
	cr_assert_stdout_eq_str(". ");
	free(map->map);
	free(map);
}

Test(choice_display_me, test3)
{
	map_t *map = mmaapp();

	cr_redirect_stdout();
	choice_display_me(0, 7, map);
	cr_assert_stdout_eq_str("2\n");
	free(map->map);
	free(map);
}
Test(choice_display_me, test4)
{
	map_t *map = mmaapp();

	map->map[0][0] = -1;
	map->map[0][1] = -2;
	cr_redirect_stdout();
	choice_display_me(0, 0, map);
	choice_display_me(0, 1, map);
	cr_assert_stdout_eq_str("x o \n");
	free(map->map);
	free(map);
}
Test(display_map_me, test1)
{
	char real[] = " |A B C D E F G H\n\
-+---------------\n1|. 1 . . . . . 2\n2|. . . . . . . .\n3|. . . . . . . .\n\
4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n\
8|. . . . . . . .\n";
	map_t *map = mmaapp();

	cr_redirect_stdout();
	display_map_me(map);
	cr_assert_stdout_eq_str(real);
	free(map->map);
	free(map);
}
