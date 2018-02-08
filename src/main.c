/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header_navy.h"

int	main(int ac, char **av)
{
	if (ac == 2 || ac == 3)
		my_navy(ac - 1, &av[1]);
	return (84);
}
