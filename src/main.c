/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header_navy.h"
#include "my.h"
void	display_help(void);

int	main(int ac, char **av)
{
	int res = 84;

	if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		display_help();
	if (ac == 2 || ac == 3)
		res = my_navy(ac - 1, &av[1]);
	return (res);
}
