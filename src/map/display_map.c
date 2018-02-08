/*
** EPITECH PROJECT, 2017
** display_map
** File description:
** display_map
*/

#include "header_navy.h"
#include "my_printf.h"

void	choice_display_enemy(int y, int x, map_t *map)
{
	switch (map->map[y][x]) {
		case 0: my_printf(".");
			break;
		case 1: my_printf("x");
			break;
		case 2: my_printf("o");
			break;
	}
	if (x < map->x - 1)
		my_printf(" ");
	else
		my_printf("\n");
}
void	display_map_enemy(map_t *map)
{
	char first[] = " |A B C D E F G H\n\
-+---------------\0";
	int y = 0;
	int x = 0;

	my_printf("%s\n", first);
	while (y != map->y) {
		x = 0;
		my_printf("%i|", y + 1);
		while (x != map->x) {
			choice_display_enemy(y, x, map);
			x++;
		}
		y++;
	}
}
void	choice_display_me(int y, int x, map_t *map)
{
	switch (map->map[y][x]) {
		case 0: my_printf(".");
			break;
		case -1: my_printf("x");
			break;
		case -2: my_printf("o");
			break;
		default:my_printf("%i", map->map[y][x]);
			break;
	}
	if (x < map->x - 1)
		my_printf(" ");
	else
		my_printf("\n");
}
void	display_map_me(map_t *map)
{
	char first[] = " |A B C D E F G H\n\
-+---------------\0";
	int y = 0;
	int x = 0;

	my_printf("%s\n", first);
	while (y != map->y) {
		x = 0;
		my_printf("%i|", y + 1);
		while (x != map->x) {
			choice_display_me(y, x, map);
			x++;
		}
		y++;
	}
}
