/*
** EPITECH PROJECT, 2017
** translate_coordonate
** File description:
** translate_coordonate
*/

#include <stdlib.h>
#include "header_navy.h"
#include "my.h"

point_t	*translate_coordonate(char *msg)
{
	point_t *p = NULL;

	if (my_strlen(msg) != 2 || (p = malloc(sizeof(*p))) == NULL)
		return (NULL);
	p->x = msg[0] - 'A';
	p->y = msg[1] - '1';
	if (p->x >= 8 || p->x < 0 || p->y >= 8 || p->y < 0) {
		free(p);
		return (NULL);
	}
	return (p);
}
