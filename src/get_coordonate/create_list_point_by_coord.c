/*
** EPITECH PROJECT, 2017
** create_list_point_by_coord
** File description:
** create_list_point_by_coord
*/

#include <stdlib.h>
#include "header_navy.h"
#include "my.h"

int	add_point_list(linked_list_t *list, int x, int y, char c)
{
	point_t *point = malloc(sizeof(*point));

	if (point == NULL || list == NULL)
		return (-1);
	point->x = x;
	point->y = y;
	point->value = c;
	create_node(list, point);
	return (1);
}
int	second_put_coord_in_list_point(linked_list_t *list, coord_t *cor)
{
	int var;
	int revar;
	int size = cor->size;

	if (cor->pa->x < cor->pb->x) {
		var = cor->pa->x;
		revar = cor->pb->x;
	} else {
		var = cor->pb->x;
		revar = cor->pa->x;
	}
	while (var <= revar) {
		if (add_point_list(list, var, cor->pa->y, size + '0') == -1)
			return (-1);
		var++;
	}
	return (1);
}
int	first_put_coord_in_list_point(linked_list_t *list, coord_t *cor)
{
	int var;
	int revar;
	int size = cor->size;

	if (cor->pa->y < cor->pb->y) {
		var = cor->pa->y;
		revar = cor->pb->y;
	} else {
		var = cor->pb->y;
		revar = cor->pa->y;
	}
	while (var <= revar) {
		if (add_point_list(list, cor->pa->x, var, size + '0') == -1)
			return (-1);
		var++;
	}
	return (1);
}

int	put_coord_in_list_point(linked_list_t *list, coord_t *cor)
{
	if (cor->pa->x == cor->pb->x)
		first_put_coord_in_list_point(list, cor);
	else
		second_put_coord_in_list_point(list, cor);
	return (1);
}
linked_list_t	*create_list_point_by_coord(coord_t **cor)
{
	int i = 0;
	linked_list_t *list = malloc(sizeof(*list));

	if (list == NULL)
		return (NULL);
	list->next = NULL;
	while (i != NB_ARGU) {
		put_coord_in_list_point(list, cor[i]);
		i++;
	}
	list = list->next;
	return (list);
}
