/*
** EPITECH PROJECT, 2017
** receive_message
** File description:
** receive_message
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_navy.h"
#include "my.h"
int	recuperate_info(void);
int	put_point_map_me(map_t *map, point_t *p);
int	send_message(int v);

int	receive_message(navy_t *nav)
{
	point_t	*p = malloc(sizeof(*p));
	int value;

	if (p == NULL)
		return (-1);
	my_printf("waiting for enemy's attack...\n");
	p->x = recuperate_info();
	p->y = recuperate_info();
	usleep(200);
	value = put_point_map_me(nav->map_me, p);
	send_message(value);
	switch (value) {
		case 1: my_printf("hit\n\n");
			break;
		case 0: my_printf("missed\n\n");
			break;
	}
	free(p);
	return (1);
}
