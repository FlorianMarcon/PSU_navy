/*
** EPITECH PROJECT, 2017
** destroy_nav
** File description:
** destroy_nav
*/

#include <stdlib.h>
#include "header_navy.h"

void	destroy_nav(navy_t *nav)
{
	free(nav->map_me->map);
	free(nav->map_you->map);
	free(nav->map_me);
	free(nav->map_you);
	free(nav);
}
