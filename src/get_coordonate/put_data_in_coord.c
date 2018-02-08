/*
** EPITECH PROJECT, 2017
** put_data_in_coord
** File description:
** put_data_in_coord
*/

#include <stdlib.h>
#include "header_navy.h"
#include "my.h"
point_t	*put_coordonate_in_point(char col, char line);
void	destroy_coord(coord_t *cor);
int	absolue(int var);

int	verify_coord(coord_t *cor)
{
	int var = absolue(cor->pa->y - cor->pb->y);

	if (cor->pa->x == cor->pb->x && var != cor->size - 1)
		return (0);
	var = absolue(cor->pa->x - cor->pb->x);
	if (cor->pa->y == cor->pb->y && var != cor->size - 1)
		return (0);
	return (1);
}

coord_t	*put_data_in_coord(char *str)
{
	coord_t *cor;

	if (my_strlen(str) != 7)
		return (NULL);
	if ((cor = malloc(sizeof(*cor))) == NULL)
		return (NULL);
	cor->size = str[0] - '0';
	cor->pa = NULL;
	cor->pb = NULL;
	if (cor->size <= 1 || cor->size > 5) {
		destroy_coord(cor);
		return (NULL);
	}
	cor->pa = put_coordonate_in_point(str[2], str[3]);
	cor->pb = put_coordonate_in_point(str[5], str[6]);
	if (cor->pa == NULL || cor->pb == NULL || verify_coord(cor) == 0) {
		destroy_coord(cor);
		return (NULL);
	}
	return (cor);
}
