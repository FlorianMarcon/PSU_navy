/*
** EPITECH PROJECT, 2017
** destroy_coord
** File description:
** destroy_coord
*/

#include <stdlib.h>
#include "header_navy.h"

void	destroy_coord(coord_t *cor)
{
	if (cor != NULL) {
		if (cor->pa != NULL)
			free(cor->pa);
		if (cor->pb != NULL)
			free(cor->pb);
		free(cor);
	}
}
