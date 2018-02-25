/*
** EPITECH PROJECT, 2017
** wait_message
** File description:
** wait_message
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "header_navy.h"
#include "get_next_line.h"
point_t	*translate_coordonate(char *msg);
int	send_message(int v);
int	recuperate_info(void);
int	put_point_map_enemy(map_t *map, point_t *p, int value);

int	all_send(point_t *p)
{
	if (send_message(p->x) == -1)
		return (0);
	usleep(200);
	if (send_message(p->y) == -1)
		return (0);
	return (1);
}

int	wait_return(navy_t *nav, point_t *p)
{
	int value = recuperate_info();

	put_point_map_enemy(nav->map_you, p, value);
	return (value);
}
int	second_party_wait_message(navy_t *nav, point_t *p, char *msg)
{
	int value;

	if (all_send(p) == 0)
		return (0);
	value = wait_return(nav, p);
	my_printf("%s: \0", msg);
	switch (value) {
		case 1: my_printf("hit\n\n");
			break;
		case 0: my_printf("missed\n\n");
			break;
	}
	return (1);
}
int	wait_message(navy_t *nav)
{
	point_t *p = NULL;
	char *str = NULL;

	while (p == NULL) {
		my_printf("attack:	\0");
		str = get_next_line(0);
		p = translate_coordonate(str);
		if (p == NULL) {
			my_printf("wrong position\n\0");
			free(str);
		}
	}
	if (second_party_wait_message(nav, p, str) == 0)
		return (0);
	free(p);
	free(str);
	return (1);
}
