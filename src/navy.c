/*
** EPITECH PROJECT, 2017
** my_navy
** File description:
** my_navy
*/

#include "my.h"
#include "header_navy.h"

int	my_navy(int nb_argu, char **av)
{
	int res = 84;

	if (nb_argu == 1)
		res = first_player(av[0]);
	else
		res = second_player(av);
	return (res);
}
