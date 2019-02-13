/*
** EPITECH PROJECT, 2017
** put_coordonate_in_point
** File description:
** put_coordonate_in_point
*/

#include <stdlib.h>
#include "header_navy.h"
int	verify_coordonate(int x, int y);

point_t	*put_coordonate_in_point(char col, char line)
{
	int x = col - 'A';
	int y = line - '1';
	point_t *point;

	if (verify_coordonate(x, y) == 0)
		return (NULL);
	if ((point = malloc(sizeof(*point))) == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}
